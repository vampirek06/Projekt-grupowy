//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
#define F_CPU 8000000
#define TIMER_COUNT 100
#define PRESCALER 8
#define TIMER_HIGH F_CPU/(100*PRESCALER)-1
#define PRZYBLIZANIE 1
#define ODDALANIE 0

char chars[512];

#include "Resources.h"

#include <avr/io.h>
#include <util/delay.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <avr/interrupt.h>

//czesc odnosnie kart SD
#define CS (1<<PB2)
#define MOSI (1<<PB3)
#define MISO (1<<PB4)
#define SCK (1<<PB5)
#define CS_DDR DDRB
#define CS_ENABLE() (PORTB &= ~CS)
#define CS_DISABLE() (PORTB |= CS)


void SPI_init() {
	CS_DDR |= CS; // SD card circuit select as output
	DDRB |= MOSI + SCK; // MOSI and SCK as outputs
	PORTB |= MISO; // pullup in MISO, might not be needed

	// Enable SPI, master, set clock rate fck/128
	SPCR = (1<<SPE) | (1<<MSTR) | (1<<SPR0) | (1<<SPR1);
}

unsigned char SPI_write(unsigned char ch) {
	SPDR = ch;
	while(!(SPSR & (1<<SPIF))) {}
	return SPDR;
}

void SD_command(unsigned char cmd, unsigned long arg, unsigned char crc, unsigned char read, int xPos) {
	unsigned char i, buffer[8];

	GLI_DrawString(0, xPos, &g_SmallFont, "CMD");

	CS_ENABLE();
	SPI_write(cmd);
	SPI_write(arg>>24);
	SPI_write(arg>>16);
	SPI_write(arg>>8);
	SPI_write(arg);
	SPI_write(crc);

	for(i=0; i<read; i++){
		buffer[i] = SPI_write(0xFF);
	}


	CS_DISABLE();

	for(i=0; i<read; i++) {
		GLI_DrawString(20*i+30, xPos, &g_SmallFont, " ");
		GLI_DrawHexInteger(20*i+40,xPos, &g_SmallFont,buffer[i] );
	}

}

typedef unsigned char BOOL;

//TODO
//zmienic nazwy zmiennych bo te sa bardzo mylace. Co sie dac wywalic do define'ow.

#define TRUE 1
#define FALSE 0

int iteracja = 0;
 int timerCount = 0;

char hallString[6];
char potentiometerString[6];
char numberOfInterruptsString[6];
char timerString[6];
BOOL analog_flag = TRUE;
BOOL flagaPrzyblizanie = PRZYBLIZANIE;
BOOL histereza = TRUE;
int timerValue;

int potencjometrNapiecie;
int czujnikNapiecie;

//TODO
//Zmienic nazwe funkcji bo ta jest troche mylaca. I wywalic do innego modulu
void ADCInitialize(){
	ACSR |= (1<<ACIE);
	ACSR |= (1<<ACIS1);
	ACSR |= (1<<ACIS0);
}

int ADCsingleREAD(uint8_t adctouse)
{
	int ADCval;

	ADMUX = adctouse;         // use proper ADC (form PC0 to PC5)
	ADMUX |= (1 << REFS0);    // use AVcc as the reference
	ADMUX &= ~(1 << ADLAR);   // clear for 10 bit resolution

	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);    // 128 prescale for 8Mhz
	ADCSRA |= (1 << ADEN);    // Enable the ADC
	ADCSRA |= (1 << ADSC);    // Start the ADC conversion

	while(ADCSRA & (1 << ADSC));      // Thanks T, this line waits for the ADC to finish

	ADCval = ADCL;
	ADCval = (ADCH << 8) + ADCval;    // ADCH is read so ADC can be updated again

	return ADCval;
}

int main(void)
{
	//TODO
	//Napisac jakos inicjowanie ADC
	//Initialize analog comparator

	//ADCInitialize();
	timerInitializeTimer1();
	timerInitializeTimer2();
	GLI_Initialize();


	sei();
	GLI_Clear(GLI_COLOR_BLACK);
	GLI_DrawString(2, 30, &g_SmallFont, timerString);
	GLI_Present();

	SPI_init();

	// ]r:10
	CS_DISABLE();
	for(int i=0; i<10; i++) // idle for 1 bytes / 80 clocks
	SPI_write(0xFF);

	while(1)
	{

		//TODO
		//Cala obsluga wyswietlacza ma sie znajdowac w obsludze przerwania od timera1
		//Od timera 1 bo timer1 jest 16 bitowy
		czujnikNapiecie = ADCsingleREAD(5);

		sprintf(potentiometerString,"%d", potencjometrNapiecie);
		sprintf(hallString,"%d", czujnikNapiecie);
		sprintf(timerString, "%d", timerValue);

		SD_command(0x40, 0x00000000, 0x95, 8, 2);
		GLI_Present();


		//GLI_Clear(GLI_COLOR_BLACK);
		//GLI_DrawInteger(2, 0, &g_SmallFont , czujnikNapiecie);
		//GLI_DrawHexInteger(2, 10, &g_SmallFont , 10);
		//GLI_Present();

		//GLI_DrawString(2, 0, &g_SmallFont, "NAPIECIE NA CZUJNI");
		//GLI_DrawString(2, 10, &g_SmallFont, hallString);
		//GLI_DrawString(2, 20, &g_SmallFont, "NAPIECIE NA POTEM");
		//GLI_DrawString(2, 30, &g_SmallFont, timerString);
		//GLI_Present();

		changeHisteresisFlag();
		_delay_ms(50);
	}

	return 0;
}

void changeHisteresisFlag(){
	if(ADCsingleREAD(5)<550){
		histereza = TRUE;
	}
}

//Todo
//Timery w jedna funkcjê i wywalic do jednego modulu.
void timerInitializeTimer1(void){
	TCCR1B = (1<<WGM12)|(1<<CS11);  //setting CTC mode (clear time on compare), and prescaler = 8
	OCR1A = TIMER_HIGH;
	TIMSK1 |= (1<<OCIE1A); //enables interrupts

}

//TODO
//Napisac jakos sensownie te inicjalizacje. Najlepiej jeszcze przeniesc j¹ do innego modulu
void timerInitializeTimer2(void){
	TCCR2A = (1<<WGM21);
	TCCR2B = (1<<CS20)|(1<<CS21)|(1<<CS22);
	OCR2A = 217;
	TIMSK2 |= (1<<OCIE2A);
}

//TODO
//Obsluga komparatora analogowego. Komparator odpowiada za sprawdzanie czy magnes przejechal przez czujnik Halla. Jesli tak przerwanie jest obs³ugiwane.
SIGNAL(ANALOG_COMP_vect)
{
	ACSR &= ~(1<<ACIS1);
	ACSR |= (1<<ACIS0);

	if(histereza){
		timerValue = timerCount;
		timerCount = 0;
		histereza = FALSE;
	}
}

//W tym przerwaniu ma byc obslugiwana obsluga wyswietlacza. Mysle ze odswiezanie wyswietlacza co 0.5s bedzie okej
ISR(TIMER1_COMPA_vect){        //This is our interrupt service routine
	/*timerCount++;
	ACSR |= (1<<ACIS1);
	ACSR |= (1<<ACIS0);
	*/
}

//TODO
//Tutaj jest czytany timer i na razie jest ustawiona czestotliwosc na 36 Hz. Ale to mozna podkercic do 100Hz (albo lepiej)
//Czestotliwosc oczywiscie ustawiamy w Timer initialize
ISR(TIMER2_COMPA_vect){        //This is our interrupt service routine
	timerCount++;
	ACSR |= (1<<ACIS1);
	ACSR |= (1<<ACIS0);
}


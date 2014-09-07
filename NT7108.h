//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
#ifndef NT7108_H
#define NT7108_H


#include <avr/io.h>


//------------------------------------------------------------------------------
// Data and control ports
//------------------------------------------------------------------------------
#define NT7108_DATA_DDR         DDRD
#define NT7108_DATA_PORT        PORTD
#define NT7108_DATA_PIN         PIND

#define NT7108_CTRL_DDR         DDRC
#define NT7108_CTRL_PORT        PORTC


//------------------------------------------------------------------------------
// Control port bits
//------------------------------------------------------------------------------
#define NT7108_CS1              4
#define NT7108_CS2              3
//#define NT7108_RST              5
#define NT7108_RW               1
#define NT7108_DI               0
#define NT7108_E                2
//#define NT7108_LED              5


//------------------------------------------------------------------------------
// Instructions
//------------------------------------------------------------------------------
#define NT7108_DISPLAY_ON       0x3f
#define NT7108_DISPLAY_OFF      0x3e

#define NT7108_Y_ADDRESS(y)     (0x40 | (((unsigned char)(y)) & 0x3f))
#define NT7108_X_ADDRESS(x)     (0xb8 | (((unsigned char)(x)) & 0x07))
#define NT7108_Z_ADDRESS(z)     (0xc0 | (((unsigned char)(z)) & 0x3f))

#define NT7108_ADDRESS(y)       NT7108_Y_ADDRESS(y)
#define NT7108_PAGE(x)          NT7108_X_ADDRESS(x)
#define NT7108_START_LINE(z)    NT7108_Z_ADDRESS(z)


//------------------------------------------------------------------------------
// Status read
//------------------------------------------------------------------------------
#define NT7108_IS_BUSY(s)       ((s) & (1 << 7))
#define NT7108_IS_ON(s)         ((s) & (1 << 5))
#define NT7108_IS_OFF(s)        (!IS_ON(s))
#define NT7108_IS_RESET(s)      ((s) & (1 << 4))


//------------------------------------------------------------------------------
#define NT7108_DELAY() __asm__ __volatile__ ("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop")


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void NT7108_Initialize(void);
void NT7108_WriteInstruction(unsigned char ChipSelect, unsigned char Data);
void NT7108_WriteData(unsigned char ChipSelect, unsigned char Data);
unsigned char NT7108_ReadStatus(unsigned char ChipSelect);
unsigned char NT7108_ReadData(unsigned char ChipSelect);


#endif
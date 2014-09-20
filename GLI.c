//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
#include "GLI.h"
#include "NT7108.h"

#include <avr/pgmspace.h>

#include <string.h>


//------------------------------------------------------------------------------
unsigned char g_DisplayBuffer[8][128];


//------------------------------------------------------------------------------
void GLI_Initialize(void)
{
    NT7108_Initialize();

    NT7108_WriteInstruction(NT7108_CS1, NT7108_DISPLAY_ON);
    NT7108_WriteInstruction(NT7108_CS2, NT7108_DISPLAY_ON);

    NT7108_WriteInstruction(NT7108_CS1, NT7108_START_LINE(0));
    NT7108_WriteInstruction(NT7108_CS2, NT7108_START_LINE(0));
}


//------------------------------------------------------------------------------
void GLI_Present(void)
{
    unsigned char Page, Address;
    unsigned char *pData1 = &g_DisplayBuffer[0][0];
    unsigned char *pData2 = &g_DisplayBuffer[0][64];

    for (Page = 0; Page < 8; Page++)
    {
        NT7108_WriteInstruction(NT7108_CS1, NT7108_PAGE(Page));
        NT7108_WriteInstruction(NT7108_CS2, NT7108_PAGE(Page));

        NT7108_WriteInstruction(NT7108_CS1, NT7108_ADDRESS(0));
        NT7108_WriteInstruction(NT7108_CS2, NT7108_ADDRESS(0));

        for (Address = 0; Address < 64; Address++)
        {
            NT7108_WriteData(NT7108_CS1, *pData1++);
            NT7108_WriteData(NT7108_CS2, *pData2++);
        }

        pData1 += 64;
        pData2 += 64;
    }
}


//------------------------------------------------------------------------------
void GLI_Clear(unsigned char Color)
{
    memset(g_DisplayBuffer, Color, sizeof(g_DisplayBuffer));
}


//------------------------------------------------------------------------------
void GLI_SetPixel(unsigned char x, unsigned char y, unsigned char Color)
{
    x = 63 - x;

    if (Color)
        g_DisplayBuffer[x / 8][y] |= (1 << (x % 8));
    else
        g_DisplayBuffer[x / 8][y] &= ~(1 << (x % 8));
}


//------------------------------------------------------------------------------
void GLI_StrokeRectangle(unsigned char Left, unsigned char Top,
                         unsigned char Right, unsigned char Bottom,
                         unsigned char Color)
{
    unsigned char i;

    for (i = Left; i <= Right; i++)
    {
        GLI_SetPixel(i, Top, Color);
        GLI_SetPixel(i, Bottom, Color);
    }

    for (i = Top; i <= Bottom; i++)
    {
        GLI_SetPixel(Left, i, Color);
        GLI_SetPixel(Right, i, Color);
    }
}


//------------------------------------------------------------------------------
void GLI_DrawBitmap(unsigned char x, unsigned char y, const GLI_BITMAP *pBitmap)
{
    unsigned char i, j, Color;
    const unsigned char *pData = pBitmap->pData;
    unsigned char iBit = 0;

    //for (i = 127; i >(127- pBitmap->Height); i--)
	for (i = 0; i < pBitmap->Height; i++)
    {
        for (j = 0; j <pBitmap->Width; j++)
        {
            Color = pgm_read_byte(pData) & (0x80 >> iBit);

            GLI_SetPixel(x + j, y - i, Color);

            iBit++;

            if (iBit == 8)
            {
                pData++;
                iBit = 0;
            }
        }
    }
}

void GLI_DrawInteger(unsigned char y, unsigned char x, const GLI_FONT *pFont, int integerToWrite){
	char stringToDraw[10];
	sprintf(stringToDraw,"%d", integerToWrite);
	GLI_DrawString(y,x,pFont,stringToDraw);
}

void GLI_DrawHexInteger(unsigned char y, unsigned char x, const GLI_FONT *pFont, int hexInteger){
	char charactersToDraw[10];
	if(((hexInteger>>4) & 15) < 10){
		charactersToDraw[0] = '0' + ((hexInteger>>4)&15);
	}
	else{
		charactersToDraw[0] = 'A' + ((hexInteger>>4)&15-10);
	}
	hexInteger <<= 4;
	if(((hexInteger>>4) & 15) < 10){
		charactersToDraw[1] = '0' + ((hexInteger>>4)&15);
	}
	else{
		charactersToDraw[1] = 'A' + ((hexInteger>>4)&15-10);
	}

	GLI_DrawString(y,x,pFont,charactersToDraw);

}

//------------------------------------------------------------------------------
void GLI_DrawString(unsigned char y, unsigned char x, const GLI_FONT *pFont, const char *pszString)
{
	int y1 = x;
	int x1 =127 - y;
    GLI_BITMAP Bitmap;
    Bitmap.Width = pFont->CharWidth;
    Bitmap.Height = pFont->CharHeight;

    for (; *pszString; pszString++)
    {
        Bitmap.pData = pFont->pData + pFont->cbCharSize * (*pszString - pFont->CharCodeStart);

        GLI_DrawBitmap(y1, x1, &Bitmap);

		//x += pFont->CharWidth;
        x1 -= pFont->CharHeight;
		//x += pFont->CharWidth;
		//y +=4;
    }
}
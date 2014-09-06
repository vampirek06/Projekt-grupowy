//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
#include "Resources.h"

#include <avr/pgmspace.h>


//------------------------------------------------------------------------------
// Block bitmap
//------------------------------------------------------------------------------
const unsigned char PROGMEM g_pBlockBitmapData[] =
{
    0xfe, 0x1b, 0x6d, 0x87, 0xf0
};


const GLI_BITMAP g_BlockBitmap =
{
    6,
    6,
    g_pBlockBitmapData
};


//------------------------------------------------------------------------------
// Small font
//------------------------------------------------------------------------------
const unsigned char PROGMEM g_pSmallFontData[] =
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // space 
    0x10, 0x41, 0x04, 0x00, 0x40, 0x00, //!
    0x28, 0xa0, 0x00, 0x00, 0x00, 0x00, //"
    0x00, 0x57, 0xca, 0x7d, 0x40, 0x00, //#
    0x10, 0xe3, 0x04, 0x18, 0xe1, 0x00, // $
    0x25, 0x53, 0x8e, 0x55, 0x20, 0x00, // %
    0x10, 0xa3, 0x15, 0x48, 0xd0, 0x00, // &
    0x10, 0x40, 0x00, 0x00, 0x00, 0x00, //'
    0x0c, 0x42, 0x08, 0x20, 0x40, 0xc0, //(
    0x60, 0x40, 0x82, 0x08, 0x46, 0x00, //)
    0x10, 0xa1, 0x0a, 0x00, 0x00, 0x00, //*
    0x00, 0x00, 0x04, 0x38, 0x40, 0x00, //+
    0x00, 0x00, 0x00, 0x00, 0x41, 0x08, //,
    0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, // -
    0x00, 0x00, 0x00, 0x00, 0x40, 0x00, //.
    0x04, 0x20, 0x84, 0x10, 0x82, 0x00, // /
    0x7c, 0x8a, 0x92, 0xa2, 0x7c, 0x00,// 0
    0x00, 0x42, 0xFE, 0x02, 0x00, 0x00, //1
    0x42, 0x86, 0x8a, 0x92, 0x62, 0x00, //2
    0x84, 0x82, 0xa2, 0xd2, 0x8c, 0x00, //3
    0x18, 0x28, 0x48, 0xfe, 0x08, 0x00, //4
    0xe4, 0xa2, 0xa2, 0xa2, 0x9c, 0x00, //5
    0x3c, 0x52, 0x92, 0x92, 0x0c, 0x00, //6
    0x86, 0x88, 0x90, 0xa0, 0xc0, 0x00, //7
    0x6c, 0x92, 0x92, 0x92, 0x6c, 0x00, //8
    0x60, 0x92, 0x92, 0x94, 0x78, 0x00, //9
    0x00, 0x01, 0x00, 0x00, 0x40, 0x00, //:
    0x00, 0x01, 0x00, 0x00, 0x41, 0x08, //;
    0x00, 0x10, 0x8c, 0x08, 0x10, 0x00, //<
    0x00, 0x03, 0xc0, 0x3c, 0x00, 0x00, //=
    0x00, 0x81, 0x03, 0x10, 0x80, 0x00, //>
    0x38, 0x10, 0x84, 0x00, 0x40, 0x00, //?
    0x18, 0x94, 0xd5, 0x5d, 0x03, 0xc0, //@
    0x7E, 0x88, 0x88, 0x88, 0x7E, 0x00, //A
    0xFE, 0x92, 0x92, 0x92, 0x6c, 0x00, //B
    0x7c, 0x82, 0x82, 0x82, 0x44, 0x00, //C
    0xfe, 0x82, 0x82, 0x44, 0x38, 0x00, //D
    0xfe, 0x92, 0x92, 0x92, 0x82, 0x00, //E
    0xfe, 0x90, 0x90, 0x90, 0x80, 0x00, //F
    0x7c, 0x82, 0x82, 0x8a, 0x4c, 0x00, //G
    0xfe, 0x10, 0x10, 0x10, 0xfe, 0x00, //H
    0x00, 0x82, 0xFE, 0x82, 0x00, 0x00, // I
    0x04, 0x02, 0x82, 0xfc, 0x80, 0x00, //J
    0xFE, 0x10, 0x28, 0x44, 0x82, 0x00, //K
    0xFE, 0x02, 0x02, 0x02, 0x02, 0x00, //L
    0xfe, 0x40, 0x20, 0x40, 0xfe, 0x00, //M
    0xfe, 0x20, 0x10, 0x08, 0xfe, 0x00, //N
    0x7c, 0x82, 0x82, 0x82, 0x7c, 0x00, //O
    0x7e, 0x90, 0x90, 0x90, 0x60, 0x00, //P
    0x7c, 0x82, 0x8a, 0x84, 0x7a, 0x00, //Q
    0xFE, 0x90, 0x98, 0x94, 0x62, 0x00, //R
    0x62, 0x92, 0x92, 0x92, 0x8c, 0x00, //S
    0x80, 0x80, 0xfe, 0x80, 0x80, 0x00, //T
    0xfc, 0x02, 0x02, 0x02, 0xfc, 0x00, //U
    0xfe, 0x04, 0x08, 0x04, 0xfe, 0x00, //V
    0xfe, 0x04, 0x08, 0x04, 0xfe, 0x00, //W
    0xc6, 0x28, 0x10, 0x28, 0xc6, 0x00, //X
    0x01, 0x12, 0x84, 0x10, 0x40, 0x00, //Y
    0x86, 0x8a, 0x92, 0xa2, 0xc2, 0x00, //Z
    0x18, 0x41, 0x04, 0x10, 0x41, 0x80, //[
    0x40, 0x82, 0x04, 0x10, 0x20, 0x80, // (backslash)
    0x30, 0x41, 0x04, 0x10, 0x43, 0x00, //]
    0x10, 0xa2, 0x91, 0x44, 0x00, 0x00, //^
    0x00, 0x00, 0x00, 0x00, 0x07, 0xc0, //_
    0x20, 0x40, 0x00, 0x00, 0x00, 0x00, //`
    0x00, 0x03, 0x02, 0x38, 0xf0, 0x00,
    0x20, 0x83, 0x89, 0x24, 0xe0, 0x00,
    0x00, 0x01, 0x88, 0x20, 0x60, 0x00,
    0x08, 0x23, 0x92, 0x48, 0xe0, 0x00,
    0x00, 0x01, 0x0e, 0x20, 0x60, 0x00,
    0x0c, 0x43, 0xc4, 0x10, 0x40, 0x00,
    0x00, 0x01, 0xc9, 0x3c, 0x13, 0x80,
    0x20, 0x82, 0x8d, 0x24, 0x90, 0x00,
    0x10, 0x03, 0x04, 0x10, 0x40, 0x00,
    0x08, 0x03, 0x82, 0x08, 0x23, 0x00,
    0x20, 0x82, 0x8c, 0x28, 0x90, 0x00,
    0x30, 0x41, 0x04, 0x10, 0x40, 0x00,
    0x00, 0x05, 0x5f, 0x55, 0x50, 0x00,
    0x00, 0x02, 0x8d, 0x24, 0x90, 0x00,
    0x00, 0x01, 0x89, 0x24, 0x60, 0x00,
    0x00, 0x03, 0x89, 0x24, 0xe2, 0x00,
    0x00, 0x03, 0x92, 0x48, 0xe0, 0x80,
    0x00, 0x02, 0x8c, 0x20, 0x80, 0x00,
    0x00, 0x01, 0x8c, 0x08, 0xc0, 0x00,
    0x00, 0x43, 0xc4, 0x10, 0x20, 0x00,
    0x00, 0x02, 0x49, 0x2c, 0x50, 0x00,
    0x00, 0x02, 0x49, 0x18, 0x60, 0x00,
    0x00, 0x05, 0x55, 0x38, 0xa0, 0x00,
    0x00, 0x02, 0x46, 0x18, 0x90, 0x00,
    0x00, 0x02, 0x49, 0x18, 0x67, 0x00,
    0x00, 0x03, 0x86, 0x20, 0xe0, 0x00,
    0x08, 0x41, 0x08, 0x10, 0x40, 0x80,
    0x10, 0x41, 0x04, 0x10, 0x41, 0x00,
    0x20, 0x41, 0x02, 0x10, 0x42, 0x00,
    0x00, 0x00, 0x0d, 0x48, 0x00, 0x00
};

const GLI_FONT g_SmallFont =
{
    8,
    6,
    6,
    32,
    g_pSmallFontData
};


//------------------------------------------------------------------------------
// Large font
//------------------------------------------------------------------------------
const unsigned char PROGMEM g_pLargeFontData[] =
{
    0x00, 0x00, 0x3c, 0x06, 0x60, 0x66, 0x0c, 0x30, 0xc3, 0x0c, 0x30, 0xc3, 0x0c, 0x30, 0xc3, 0x06, 0x60, 0x66, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x18, 0x0f, 0x80, 0x18, 0x01, 0x80, 0x18, 0x01, 0x80, 0x18, 0x01, 0x80, 0x18, 0x01, 0x80, 0x18, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xfc, 0x0c, 0x60, 0x06, 0x00, 0x60, 0x06, 0x00, 0xc0, 0x0c, 0x01, 0x80, 0x30, 0x06, 0x00, 0xc0, 0x0f, 0xe0, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x7c, 0x00, 0x60, 0x06, 0x00, 0x60, 0x06, 0x03, 0xc0, 0x06, 0x00, 0x60, 0x06, 0x00, 0x60, 0x06, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0c, 0x01, 0xc0, 0x3c, 0x03, 0xc0, 0x6c, 0x0c, 0xc0, 0xcc, 0x18, 0xc1, 0xff, 0x00, 0xc0, 0x0c, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x7e, 0x06, 0x00, 0x60, 0x06, 0x00, 0x78, 0x00, 0xc0, 0x06, 0x00, 0x60, 0x06, 0x00, 0x60, 0x0c, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x3e, 0x06, 0x00, 0x60, 0x0c, 0x00, 0xfc, 0x0e, 0x60, 0xc3, 0x0c, 0x30, 0xc3, 0x0c, 0x30, 0x66, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xff, 0x00, 0x30, 0x06, 0x00, 0xc0, 0x0c, 0x01, 0x80, 0x18, 0x03, 0x00, 0x30, 0x03, 0x00, 0x60, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x7e, 0x0c, 0x30, 0xc3, 0x0c, 0x30, 0x6e, 0x03, 0x80, 0x6e, 0x0c, 0x60, 0xc3, 0x0c, 0x30, 0xc6, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x3c, 0x06, 0x60, 0xc3, 0x0c, 0x30, 0xc3, 0x0c, 0x30, 0x67, 0x03, 0xf0, 0x03, 0x00, 0x60, 0x06, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x00
};






const GLI_FONT g_LargeFont =
{
    12,
    16,
    24,
    48,
    g_pLargeFontData
};

const unsigned char PROGMEM g_pArial14Data[] = {
	0x00, 0x00, 0x00, 0x00, 0x00,// (spacja)
	0x00, 0x00, 0x5F, 0x00, 0x00,// !
	0x00, 0x07, 0x00, 0x07, 0x00,// "
	0x14, 0x7F, 0x14, 0x7F, 0x14,// #
	0x24, 0x2A, 0x7F, 0x2A, 0x12,// $
	0x23, 0x13, 0x08, 0x64, 0x62,// %
	0x36, 0x49, 0x55, 0x22, 0x50,// &
	0x00, 0x05, 0x03, 0x00, 0x00,// '
	0x00, 0x1C, 0x22, 0x41, 0x00,// (
	0x00, 0x41, 0x22, 0x1C, 0x00,// )
	0x08, 0x2A, 0x1C, 0x2A, 0x08,// *
	0x08, 0x08, 0x3E, 0x08, 0x08,// +
	0x00, 0x50, 0x30, 0x00, 0x00,// ,
	0x08, 0x08, 0x08, 0x08, 0x08,// -
	0x00, 0x30, 0x30, 0x00, 0x00,// .
	0x20, 0x10, 0x08, 0x04, 0x02,// /
	0x3E, 0x51, 0x49, 0x45, 0x3E,// 0
	0x00, 0x42, 0x7F, 0x40, 0x00,// 1
	0x42, 0x61, 0x51, 0x49, 0x46,// 2
	0x21, 0x41, 0x45, 0x4B, 0x31,// 3
	0x18, 0x14, 0x12, 0x7F, 0x10,// 4
	0x27, 0x45, 0x45, 0x45, 0x39,// 5
	0x3C, 0x4A, 0x49, 0x49, 0x30,// 6
	0x01, 0x71, 0x09, 0x05, 0x03,// 7
	0x36, 0x49, 0x49, 0x49, 0x36,// 8
	0x06, 0x49, 0x49, 0x29, 0x1E,// 9
	0x00, 0x36, 0x36, 0x00, 0x00,// :
	0x00, 0x56, 0x36, 0x00, 0x00,// ;
	0x00, 0x08, 0x14, 0x22, 0x41,// <
	0x14, 0x14, 0x14, 0x14, 0x14,// =
	0x41, 0x22, 0x14, 0x08, 0x00,// >
	0x02, 0x01, 0x51, 0x09, 0x06,// ?
	0x32, 0x49, 0x79, 0x41, 0x3E,// @
	0x7E, 0x11, 0x11, 0x11, 0x7E,// A
	0x7F, 0x49, 0x49, 0x49, 0x36,// B
	0x3E, 0x41, 0x41, 0x41, 0x22,// C
	0x7F, 0x41, 0x41, 0x22, 0x1C,// D
	0x7F, 0x49, 0x49, 0x49, 0x41,// E
	0x7F, 0x09, 0x09, 0x01, 0x01,// F
	0x3E, 0x41, 0x41, 0x51, 0x32,// G
	0x7F, 0x08, 0x08, 0x08, 0x7F,// H
	0x00, 0x41, 0x7F, 0x41, 0x00,// I
	0x20, 0x40, 0x41, 0x3F, 0x01,// J
	0x7F, 0x08, 0x14, 0x22, 0x41,// K
	0x7F, 0x40, 0x40, 0x40, 0x40,// L
	0x7F, 0x02, 0x04, 0x02, 0x7F,// M
	0x7F, 0x04, 0x08, 0x10, 0x7F,// N
	0x3E, 0x41, 0x41, 0x41, 0x3E,// O
	0x7F, 0x09, 0x09, 0x09, 0x06,// P
	0x3E, 0x41, 0x51, 0x21, 0x5E,// Q
	0x7F, 0x09, 0x19, 0x29, 0x46,// R
	0x46, 0x49, 0x49, 0x49, 0x31,// S
	0x01, 0x01, 0x7F, 0x01, 0x01,// T
	0x3F, 0x40, 0x40, 0x40, 0x3F,// U
	0x1F, 0x20, 0x40, 0x20, 0x1F,// V
	0x7F, 0x20, 0x18, 0x20, 0x7F,// W
	0x63, 0x14, 0x08, 0x14, 0x63,// X
	0x03, 0x04, 0x78, 0x04, 0x03,// Y
	0x61, 0x51, 0x49, 0x45, 0x43,// Z
	0x00, 0x00, 0x7F, 0x41, 0x41,// [
	0x02, 0x04, 0x08, 0x10, 0x20,// "\"
	0x41, 0x41, 0x7F, 0x00, 0x00,// ]
	0x04, 0x02, 0x01, 0x02, 0x04,// ^
	0x40, 0x40, 0x40, 0x40, 0x40,// _
	0x00, 0x01, 0x02, 0x04, 0x00,// `
	0x20, 0x54, 0x54, 0x54, 0x78,// a
	0x7F, 0x48, 0x44, 0x44, 0x38,// b
	0x38, 0x44, 0x44, 0x44, 0x20,// c
	0x38, 0x44, 0x44, 0x48, 0x7F,// d
	0x38, 0x54, 0x54, 0x54, 0x18,// e
	0x08, 0x7E, 0x09, 0x01, 0x02,// f
	0x08, 0x14, 0x54, 0x54, 0x3C,// g
	0x7F, 0x08, 0x04, 0x04, 0x78,// h
	0x00, 0x44, 0x7D, 0x40, 0x00,// i
	0x20, 0x40, 0x44, 0x3D, 0x00,// j
	0x00, 0x7F, 0x10, 0x28, 0x44,// k
	0x00, 0x41, 0x7F, 0x40, 0x00,// l
	0x7C, 0x04, 0x18, 0x04, 0x78,// m
	0x7C, 0x08, 0x04, 0x04, 0x78,// n
	0x38, 0x44, 0x44, 0x44, 0x38,// o
	0x7C, 0x14, 0x14, 0x14, 0x08,// p
	0x08, 0x14, 0x14, 0x18, 0x7C,// q
	0x7C, 0x08, 0x04, 0x04, 0x08,// r
	0x48, 0x54, 0x54, 0x54, 0x20,// s
	0x04, 0x3F, 0x44, 0x40, 0x20,// t
	0x3C, 0x40, 0x40, 0x20, 0x7C,// u
	0x1C, 0x20, 0x40, 0x20, 0x1C,// v
	0x3C, 0x40, 0x30, 0x40, 0x3C,// w
	0x44, 0x28, 0x10, 0x28, 0x44,// x
	0x0C, 0x50, 0x50, 0x50, 0x3C,// y
	0x44, 0x64, 0x54, 0x4C, 0x44,// z
	0x00, 0x08, 0x36, 0x41, 0x00,// {
		0x00, 0x00, 0x7F, 0x00, 0x00,// |
	0x00, 0x41, 0x36, 0x08, 0x00,// }
	0x08, 0x08, 0x2A, 0x1C, 0x08,// ->
	0x08, 0x1C, 0x2A, 0x08, 0x08 // <-
};


const GLI_FONT g_Arial14 =
{
	5,
	8,
	6,
	32,
	g_pArial14Data
};




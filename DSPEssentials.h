#pragma once

#define  PI                  3.1415926536
#define  N                   4
#define  MAX_CMPLX_NUM_CHARS 50
#define  REAL_IMG_LENGTH     4
#define  SPACE               0x20
#define  DOT                 0x2E
#define  NEGATIVE            0x2D
#define  IMAGINARY_UNIT      0x6A
#define  PLUS                0x2B
#define  COMMA               0x2C

#define  READING_VALS        0x01
#define  READING_JUNK        !(READING_VALS)
#define  MARKER              0x04
#define  WRITE_VAL_SUCCESS   0x01

typedef  short           int16;
typedef  unsigned short  uint16;

typedef enum defineNums
{
       ZERO =                0x30,
	   ONE,
	   TWO,
	   THREE,
	   FOUR,
	   FIVE,
	   SIX,
	   SEVEN,
	   EIGHT,
	   NINE
}defineNums;

typedef struct cmplx {
	float re;
	float img;
} cmplx;

cmplx Xin[N];
cmplx Xout[N];

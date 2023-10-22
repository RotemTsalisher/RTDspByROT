#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "DSPByROT.h"
#include "loggers.h"

void initCmplxArr(cmplx X[])
{
	// update values according to test case;
	X[0].re = 1;
	X[0].img = 0;
	X[1].re = 1;
	X[1].img = 0;
	X[2].re = 1;
	X[2].img = 0;
	X[3].re = 0;
	X[3].img = 0;
}

void initAllZeroCmplxArr(cmplx X[])
{
	X[0].re = 0;
	X[0].img = 0;
	X[1].re = 0;
	X[1].img = 0;
	X[2].re = 0;
	X[2].img = 0;
	X[3].re = 0;
	X[3].img = 0;
}

void floatPointDFT(cmplx Xin[], cmplx Xout[])
{
	int16 i, j, k, n;
	float angle;
	cmplx twiddle;

	for (k = 0; k < N; k++)
	{
		for (n = 0; n < N; n++)
		{
			angle = (2 * PI * n * k) / N;
			twiddle.re = cos(angle);
			twiddle.img = sin(angle);

			//if we are not sure that Xout[] is a complex array of ALL ZEROS, it is necessary to initialize the process with 0;
			// Xout[k].re = 0;
			// Xout[k].img = 0;

			Xout[k].re = Xout[k].re + (Xin[n].re) * (twiddle.re) + (Xin[n].img) * (twiddle.img);
			Xout[k].img = Xout[k].img + (Xin[n].img) * (twiddle.re) - (Xin[n].re) * (twiddle.img);
		}
	}
}

uint16 charToCmplx(char num[], cmplx* c, uint16 isImg)
{
	uint16 i;
	i = 0;
	// check for single character / double character cases
	if ((num[1] != '.') && (num[2] != '.'))
	{
		// wrong format
		return -1;
	}
	if (isImg)
	{
		c->img = atof(num);
		return 1;
	}
	else
	{
		c->re = atof(num);
		return 1;
	}
}





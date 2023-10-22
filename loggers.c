
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "loggers.h"

void printfCmplxArr(cmplx arr[])
{
	printf("[");
	for (int i = 0; i < N - 1; i++)
	{
		printfCmplx(arr[i]);
		printf(" , ");
	}
	printfCmplx(arr[N - 1]);
	printf("]\n");
}

void printfCmplx(cmplx num)
{
	float thresh = pow(10, -3);
	if ((((num.re >= 0) && (num.re < thresh)) || ((num.re < 0) && (num.re > -thresh))) && ((num.img > thresh) || (num.re < -thresh)))
	{
		printf("       %.2fj", num.img);
	}
	else if ((((num.img >= 0) && (num.img < thresh)) || ((num.img < 0) && (num.img > -thresh))) && ((num.re > thresh) || (num.re < -thresh)))
	{

		printf("%.2f        ", num.re);
	}
	else if ((((num.img >= 0) && (num.img < thresh)) || ((num.img < 0) && (num.img > -thresh))) && (((num.re >= 0) && (num.re < thresh)) || ((num.re < 0) && (num.re > -thresh))))
	{

		printf("0.00        ");
	}
	else
	{
		printf("%.2f + %.2fj", num.re, num.img);
	}
}
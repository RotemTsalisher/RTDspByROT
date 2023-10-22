#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "lowLevelSys.h"
#include "DSPByROT.h"

void readTypes(char* inputType, char* dftType);

void main()
{
	char inputType, dftType;

	inputType = ZERO;
	dftType = ZERO;
	
	do
	{
		printf("Would you like to enter a signal or would you like the system to generate a random signal?\n1. System generate a random signal\n2. I will insert a signal myself\n{enter '1' / '2'}\n");
		fseek(stdin, 0, SEEK_END);
		scanf("%c", &inputType);
	}while((inputType != ONE) && (inputType != TWO)) ;

	do
	{
		printf("for the signal's frequency representation, would you like to use standard computation or FFT?\n1. Standart DFT by definition\n2. FFT {Radix 2 algorithm}\n{enter '1' / '2'}\n");
		fseek(stdin, 0, SEEK_END);
	} while ((dftType != ONE) && (dftType != TWO));

	/* initAllZeroCmplxArr(&Xin);
	sigFileRead("sigs.txt", &Xin);
	initAllZeroCmplxArr(&Xout);
	floatPointDFT(&Xin, &Xout);
	printf("* READING INPUT FROM FILE {calling sigFileRead()}:\n");
	printf("input:  ");
	printfCmplxArr(&Xin);
	printf("* CALLING DFT FUNCTION ON INPUT SEQUENCE:\n");
	printf("output: ");
	printfCmplxArr(&Xout);  */
}
void readTypes(char* inputType, char* dftType)
{
	// read inputs from user about input type and dft type
};

void readSigFromUser(void)
{
	// read into Xin from dsp lib
}

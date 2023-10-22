#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "DSPEssentials.h"
#include "ROTFileSys.h"

void sigFileRead(char path[], cmplx arr[])
{
	FILE* pf;
	char c;
	char num[MAX_CMPLX_NUM_CHARS];
	uint16 i, k, j, flag, isNeg, rRe, rImg, writeVal;

	flag = 0; // reading junk / legit vals

	// init

	i = 0;
	j = 0;
	k = 0;
	isNeg = 0;
	rImg = 0;
	c = 0x00;
	writeVal = 0;

	pf = fopen(path, "r +");
	while (c != EOF)
	{
		flag = READING_JUNK;
		c = fgetc(pf);
		if (c == NEGATIVE)
		{
			isNeg = 1;
		}

		if ((((c >= ZERO) && (c <= NINE)) || (c == NEGATIVE)))
		{
			flag = READING_VALS;
			rImg = 0;
			do
			{
				num[i++] = c;
				c = fgetc(pf);
				if (c == IMAGINARY_UNIT)
				{
					rImg = 1;
				}

			} while ((c != COMMA) && (c != SPACE) && (c != PLUS) && (c != NEGATIVE) && (c != ']'));

			num[i] = 0x00;
			fseek(pf, -1, SEEK_CUR);
			writeVal = charToCmplx(&num, &arr[k], rImg);
			j = 0;
			i = 0;
		}
		if ((c == SPACE) && flag == (READING_VALS))
		{
			k++;
		}
	}

	fclose(pf);
}
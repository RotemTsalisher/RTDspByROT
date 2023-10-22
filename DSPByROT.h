#pragma once

#include "DSPEssentials.h"

void floatPointDFT(cmplx Xin[], cmplx Xout[]);


void initAllZeroCmplxArr(cmplx X[]);


void initCmplxArr(cmplx X[]);


uint16 charToCmplx(char num[], cmplx* c, uint16 isImg);
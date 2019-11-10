/**
 * File              : dge.h
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 11.10.2019
 * Last Modified Date: 09.11.2019
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
#ifndef DGE_H
#define DGE_H

#include "../typedef.h"

void meshgrid(vector, vector, matrixD, matrixD);
matrixD eval(double (*f)(double, double), matrixD, matrixD);
matrixD odeEulerExp(double (*)(double, double), vector, vector, double);
matrixD odeEulerExt(double (*)(double, double), vector, vector, double);
matrixD odeRK34(double (*)(double, double), vector, vector, double);

#endif

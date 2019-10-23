/**
 * File              : dge.h
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 11.10.2019
 * Last Modified Date: 22.10.2019
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
#ifndef DGE_H
#define DGE_H

#include "../typedef.h"

void meshgrid(vector, vector, matrixD, matrixD);
matrixD eval(double (*f)(double, double), matrixD, matrixD);
matrixD odeEulerExp(double (*)(double, double), vector, vector, double);
matrixD odeEulerImp(double (*)(double, double), vector, vector, double);

#endif

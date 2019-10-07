/**
 * File              : matrix.h
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 28.09.2019
 * Last Modified Date: 28.09.2019
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
/**
 * lib/matrix.h
 * Copyright (c) 2019 Philipp Zettl <philipp.zettl@godesteem.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MATRIX_H
#define MATRIX_H

#include "array.h"

#define u_int unsigned int

typedef struct matrixD {
  double *_e;
  u_int rows;
  u_int cols;
} matrixD;
typedef struct vector {
  double *_e;
  u_int size;
} vector;

matrixD initMatrix(matrixD, int, int);
vector mVecMultiplication(matrixD mat, vector vec);
vector initVec(vector, unsigned int);
void printVec(vector);
void printMat(matrixD);
int getIndex(int, int, u_int, u_int);
matrixD mScalarMult(matrixD, double);
matrixD mMatMult(matrixD, matrixD);
matrixD transpose(matrixD);

#endif

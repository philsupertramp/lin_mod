#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#include "matrix.h"
#include "styling.h"

#define SIZE sizeof

vector initVec(vector vec, uint _size){
  vec._e = calloc(_size, SIZE(double));
  vec.size = _size;
  return vec;
}

matrix initMatrix(matrix Mat, int rows, int cols){
  vector Elems;
  Elems = initVec(Elems, cols * rows);
  Mat._e = Elems._e;
  Mat.rows = rows;
  Mat.cols = cols;
  Mat = mScalarMult(Mat, 0);
  return Mat; 
}

vector mVecMultiplication(matrix mat, vector vec){
  vector result;
  result = initVec(result, mat.rows);
  register int i = 0;
  register int j = 0;

  printVec(vec);
  printMat(mat);
  register int curRow = 0;

  for(i=0;i<mat.rows;++i){
    for(j=0;j<mat.cols;++j){
      result._e[i] += mat._e[getIndex(i, j, mat.rows, mat.cols)] * vec._e[j];
    }
  }
  return result;
}

void printVec(vector vec){
  printArray(vec._e, vec.size);
}

int getIndex(int i, int j, u_int rows, u_int cols){
  return i * cols + j;
}

void printMat(matrix mat){
  printf("mat[%d x %d]: [\n", mat.rows, mat.cols);
  for(int i=0; i<mat.rows*mat.cols; ++i){
    if(i % mat.cols == 0 && i != 0) printf("\n");
    printf("\t%f", mat._e[i]);
  }
  printf("\n]\n");
}

matrix mScalarMult(matrix mat, double lambda){
  for(int i=0; i<mat.cols*mat.rows; ++i){
    mat._e[i] *= lambda;
  }
  return mat;
}

matrix mMatMult(matrix A, matrix B){
  if(A.cols != B.rows){
    cprint(RED, 1, stdout);
    printf("matrix::mMatMult::ERROR [%d x %d] * [%d x %d] not possible\n", A.rows, A.cols, B.rows, B.cols);
    cprint(RESET, 0, stdout);
    matrix ERROR;
    return ERROR;
  }

  matrix result;
  result = initMatrix(result, A.rows, B.cols);
  double a = 0., b = 0., c = 0.;
  for(int iA=0; iA<A.rows; ++iA){
    for(int jB=0; jB<B.cols; ++jB){
      c = 0.;
      for(int jA=0; jA<A.cols; ++jA){
        a = A._e[getIndex(iA, jB, A.rows, A.cols)];
        b = B._e[getIndex(jB, jA, B.rows, B.cols)];
        c += a*b;
      }
      result._e[getIndex(iA, jB, result.rows, result.cols)] = c;
    }
  }
  return result;
}

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
  // TODO: handle error
  if(A.cols != B.rows){
    cprint(RED, 1, stdout);
    printf("ERROR");
    matrix ERROR;
    return ERROR;
  }
  matrix result;
  printf("A\n");
  printMat(A);
  printf("B\n");
  printMat(B);
  result = initMatrix(result, A.rows, B.cols);
  printMat(result);
  double a = 0., b = 0.;
  for(int i=0; i<A.rows; ++i){
    for(int j=0; j<B.cols; ++j){
      for(int k=0; k<B.rows; ++k){
        a += A._e[getIndex(j, k, A.rows, A.cols)];
        b += B._e[getIndex(k, j, B.rows, B.cols)];
        result._e[getIndex(i, j, result.rows, result.cols)] = a * b;
      }
      printf("i: %d, j: %d, index: %d\n", i, j, getIndex(i, j, result.rows, result.cols));
      printf("res = %f, a*b = %f\n", result._e[getIndex(i, j, result.rows, result.cols)], a*b);
      a = 0, b = 0;
    }
  }
  return result;
}

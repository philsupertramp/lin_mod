#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#include "matrix.h"
#include "array.h"

#define SIZE sizeof

vector initVec(vector vec, uint _size){
  vec._e = calloc(_size, SIZE(double));
  vec.size = _size;
  return vec;
}

matrix initMatrix(matrix Mat, int cols, int rows){
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
  return i * rows + j;
}

void printMat(matrix mat){
  printf("mat: [\n");
  for(int i=0; i<mat.rows*mat.rows; ++i){
    printf("\t%f", mat._e[i]);
    if(i % mat.cols) printf("\n");
  }
  printf("]\n");
}

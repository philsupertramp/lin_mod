#include <stdarg.h>
#include <stdlib.h>

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
  /*
   * A = [2, 3]
   * B = [3, 1]
   * C = [2, 1]
   *
   */
  result = initVec(result, mat.rows);
  register int i = 0;
  register int j = 0;

  for(i=0; i<mat.rows; ++i){
    for(j=0; j<mat.cols; ++j){
      result._e[i*(j > 0 ? j : 1)] += mat._e[i*j] * vec._e[j];
    }
  }
  return result;
}

#ifndef TEST_MATRIX_H
#define TEST_MATRIX_H

#include "../lib/matrix.h"

#define TEST void

TEST testInitMatrix(){
  matrix mat;
  mat = initMatrix(mat, 2, 2);
  assert(mat.cols == 2);
  assert(mat.rows == 2);

  printf("matrix::initMatrix is working.\n");
}

TEST testMVecMultiplication(){
  matrix mat;
  vector vec;
  vector result;
  double a[2][2] = {{2, 2},{2, 2}};
  double b[2] = {1, 2};
  mat = initMatrix(mat, 2, 2);
  vec = initVec(vec, 2);

  mat._e = a;
  vec._e = b;

  result = mVecMultiplication(mat, vec);

  assert(result._e[0] == 6.);
  assert(result._e[1] == 6.);
}

TEST testMatrix(){
  testInitMatrix();
  testMVecMultiplication();
} 

#endif

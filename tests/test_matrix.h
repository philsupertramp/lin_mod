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

TEST testInitVec(){
  vector vec;
  vec = initVec(vec, 2);

  assert(vec.size == 2);

  printf("matrix::initVec is working.\n");
}

TEST testMVecMultiplication(){
  matrix mat;
  vector vec;
  vector result;
  double a[2][2] = {{1., 2.}, {3., 4.}};
  double b[2] = {1., 2.};
  mat = initMatrix(mat, 2, 2);
  vec = initVec(vec, 2);

  mat._e = a;
  vec._e = b;

  result = mVecMultiplication(mat, vec);

  printArray(result._e, 2);
  assert(mat._e[0] == 1);

  assert(result._e[0] ==  5.);
  assert(result._e[1] == 11.);

  printf("matrix::mVecMultiplication is working\n");
}

TEST testMatrix(){
  testInitMatrix();
  testInitVec();
  testMVecMultiplication();
} 

#endif

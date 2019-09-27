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

TEST testMVecMultValues(matrix mat, vector vec, double res[], int resultSize){
  vector result;

  result = mVecMultiplication(mat, vec);

  for(int i=0; i<resultSize; ++i){
    assert(result._e[i] == res[i]);
  }
}

TEST testMVecMultiplication(){
  matrix mat;
  vector vec;
  int colA1 = 2, rowA1 = 2, sizeB1 = 2, colA2 = 2, rowA2 = 2, sizeB2 = 2;

  double a1[2][2] = {{1., 2.}, {3., 4.}};
  double a2[2][2] = {{2., 2.}, {2., 2.}};
  double b1[2] = {1., 2.};
  double b2[2] = {1., 2.};

  double resultA[2] = {5., 11.};
  double resultB[2] = {6.,  6.};


  mat = initMatrix(mat, colA1, rowA1);
  vec = initVec(vec, sizeB1);

  mat._e = a1;
  vec._e = b1;

  testMVecMultValues(mat, vec, resultA, sizeB1);

  mat._e = a2;
  vec._e = b2;

  testMVecMultValues(mat, vec, resultB, sizeB2);

  printf("matrix::mVecMultiplication is working\n");
}

TEST testMScalarMult(){
  matrix mat, result;
  double lambda = 2.;

  mat = initMatrix(mat, 2, 2);
  result = initMatrix(result, 2, 2);
  double a[2][2] = {{1., 1.}, {1., 1.}};

  mat._e = a;

  result = mScalarMult(mat, lambda);

  for(int i=0;i<result.rows*result.cols; ++i){
    assert(mat._e[i] == 2.);
  }

  printf("matrix::mScalarMult is working.\n");
}

TEST testMMatMult(){
  matrix A, B, result;

  A = initMatrix(A, 3, 3);
  B = initMatrix(B, 2, 2);
  result = initMatrix(result, 3, 2);

  double a[3][3] = {{1., 1., 1.}, {1., 1., 1.}, {1., 1., 1.}};
  double b[2][3] = {{2., 2., 2.}, {2., 2., 2.}};

  A._e = a;
  B._e = b;

  result = mMatMult(A, B);

  printMat(result);
  for(int i=0; i<6; ++i){
    assert(result._e[i] == 3);
  }

  printf("mat::mMatMult is working.\n");
}

TEST testMatrix(){
  testInitMatrix();
  testInitVec();
  testMVecMultiplication();
  testMScalarMult();
  testMMatMult();
} 

#endif

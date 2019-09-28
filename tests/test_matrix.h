#ifndef TEST_MATRIX_H
#define TEST_MATRIX_H

#include "../lib/matrix.h"
#include "../lib/stat.h"

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

TEST testMMatMultVal(matrix A, matrix B, double *res, int resRows, int resCols){
  matrix result;
  result = initMatrix(result, resRows, resCols);
  result = mMatMult(A, B);

  printMat(result);
  printArray(res, resRows * resCols);
  for(int i=0; i<resRows; ++i){
    for(int j=0; j<resCols; ++j){
      int index = getIndex(i, j, result.rows, result.cols);
      assert(round_(result._e[index], 2) == round_(res[index], 2));
    }
  }
  printf("[%d x %d] is working.\n", resRows, resCols);
}
TEST testMMatMult(){
  matrix A, B;

  A = initMatrix(A, 3, 3);
  B = initMatrix(B, 3, 2);

  double a1[3][3] = {{1., 1., 1.}, {1., 1., 1.}, {1., 1., 1.}};
  double b1[2][3] = {{2., 2., 2.}, {2., 2., 2.}};
  double res1[6] = {
    6., 6., 6.,
    6., 6., 6.
  };

  A._e = a1;
  B._e = b1;

  testMMatMultVal(A, B, res1, 3, 2);
  double a2[2][3] = {{1.,0., 0.},{0.,1., 0}};
  double b2[3][5] = {{1.,0.,0.,0.,0.}, {0.,1.,0.,0.,0.}, {0.,0.,1.,0.,0.}};
  double res2[10] = {
    1.,0.,0.,0.,0.,
    0.,1.,0.,0.,0.
  };
  A = initMatrix(A, 2, 3);
  B = initMatrix(B, 3, 5);

  A._e = a2;
  B._e = b2;

  testMMatMultVal(A, B, res2, 2, 5);

  double a3[3][2] = {
    {1., 2.},
    {3., 4.},
    {5., 6.}
  };
  double b3[2][2] = {
    {2.,  4.},
    {6., 12.}
  };
  double res3[6] = {
    14., 28.,
    30., 60.,
    46., 92.
  };
  A = initMatrix(A, 3, 2);
  B = initMatrix(B, 2, 2);

  A._e = a3;
  B._e = b3;

  printMat(A);
  printMat(B);

  testMMatMultVal(A, B, res3, 3, 2);

  printf("matrix::mMatMult is working.\n");
}

TEST testMatrix(){
  testInitMatrix();
  testInitVec();
  testMVecMultiplication();
  testMScalarMult();
  testMMatMult();

  printf("matrix is working.\n");
} 

#endif

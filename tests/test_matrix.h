/**
 * File              : test_matrix.h
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 28.09.2019
 * Last Modified Date: 13.10.2019
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
/**
 * tests/test_matrix.h
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
#ifndef TEST_MATRIX_H
#define TEST_MATRIX_H

#include "../lib/matrix.h"
#include "../lib/stat/stat.h"

#define TEST void

TEST testInitMatrix(){
  matrixD mat;
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

TEST testMVecMultValues(matrixD mat, vector vec, double res[], int resultSize){
  vector result;

  result = mVecMultiplication(mat, vec);

  for(int i=0; i<resultSize; ++i){
    assert(result._e[i] == res[i]);
  }
}

TEST testMVecMultiplication(){
  matrixD mat;
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
  matrixD mat, result;
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

TEST testMMatMultVal(matrixD A, matrixD B, double *res, int resRows, int resCols){
  matrixD result;
  result = initMatrix(result, resRows, resCols);
  result = mMatMult(A, B);

  for(int i=0; i<resRows; ++i){
    for(int j=0; j<resCols; ++j){
      int index = getIndex(i, j, result.rows, result.cols);
      assert(round_(result._e[index], 2) == round_(res[index], 2));
    }
  }
  printf("matrixD::mMatMult([%d x %d]) is working.\n", resRows, resCols);
}
TEST testMMatMult(){
  matrixD A, B;

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

  testMMatMultVal(A, B, res3, 3, 2);

  printf("matrixD::mMatMult is working.\n");
}

TEST testTransposeVal(matrixD mat, double result[], int resSize){
  matrixD res;
  res = transpose(mat);

  for(int i=0;i<resSize;++i){
    assert(res._e[i] == result[i]);
  }
}

TEST testTranspose(){
  matrixD res, mat;

  mat = initMatrix(mat, 2, 2);
  double a1[2][2] = {{1., 2.}, {3., 4.}};
  double res1[4] = {
    1., 3.,
    2., 4.
  };
  mat._e = a1;

  testTransposeVal(mat, res1, 4);

  double a2[2][3] = {{2., 2., 2.}, {3., 3., 3.}};
  double res2[6] = {
    2., 3.,
    2., 3.,
    2., 3.
  };
  mat = initMatrix(mat, 2, 3);

  mat._e = a2;

  testTransposeVal(mat, res2, 6);

  printf("matrix::transpose is working.\n");
}

TEST testInvertMatrixD(){
  double a[3][3] = {{1.4142, 2.2361, 3.1623}, {4.1231, 5.0990, 6.0828}, {7.0711, 8.0623, 9.0554}};
  matrixD A;
  A = initMatrix(A, 3, 3);
  
  A._e = a;

  matrixD invA = invertMatrixD(A);

  double res[9] = {
     10.9011, -19.9476,   9.5926,
    -21.5775,  36.3258, -16.8659,
     10.6987, -16.7654,   7.6361
  };
  printMat(invA);
  for(int i=0; i<3;++i){
    for(int j=0; j<3;++j){
      int index = getIndex(i, j, invA.cols, invA.rows);
      printf("%f==%f\n", invA._e[index] , res[index]);
    }
  }

  printf("matrix::invertMatrixD is working.\n");
}

TEST testMatrix(){
  testInitMatrix();
  testInitVec();
  testMVecMultiplication();
  testMScalarMult();
  testMMatMult();
  testTranspose();
  testInvertMatrixD();

  printf("matrix is working.\n");
} 

#endif

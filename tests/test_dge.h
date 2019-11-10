/**
 * File              : test_dge.h
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 11.10.2019
 * Last Modified Date: 10.11.2019
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
#include <math.h>
#include "../lib/source.h"
#include "../lib/typedef.h"
#include "../lib/numerics/examples.h"

double fooF(double ti, double yi){
  return ti + yi;
}

TEST testMeshgrid(){
  vector a, b;
  matrixD meshX, meshY;
  a = initVec(a, 5);
  b = initVec(b, 5);
  meshX = initMatrix(meshX, 5, 5);
  meshY = initMatrix(meshY, 5, 5);
  double cols[5] = {1., 2., 3., 4., 5.};
  double rows[5] = {0.5, 0.6, 0.7, 0.8, 0.9};

  assignVals(a._e, cols, 5);
  assignVals(b._e, rows, 5);
  TEST test(vector A, vector B, matrixD MeshX, matrixD MeshY){
    meshgrid(A, B, MeshX, MeshY);
    for(int i=0; i<MeshX.rows;++i){
      for(int j=0; j<MeshX.cols;++j){
        assert(MeshX._e[getIndex(i, j, MeshX.rows, MeshX.cols)] == A._e[j]);
      }
    }
    printf("Y\n");
    printMat(MeshY);
    for(int i=0; i<MeshY.cols;++i){
      for(int j=0; j<MeshY.rows;++j){
        assert(MeshY._e[getIndex(j, i, MeshY.rows, MeshY.cols)] == B._e[j]);
      }
    }
  }
  test(a, b, meshX, meshY);
  double rows2[2] = {1., 2.};

  b = initVec(b, 2);
  meshX = initMatrix(meshX, 2, 5);
  meshY = initMatrix(meshY, 2, 5);

  assignVals(a._e, cols , 5);
  assignVals(b._e, rows2, 2);
  
  test(a, b, meshX, meshY);
  printf("numerics::DGE::meshgrid is working.\n");
}

TEST testEval(){
  matrixD t, y, res;
  t = initMatrix(t, 3, 3);
  y = initMatrix(y, 3, 3);

  double t1[3][3] = {
    {1., 2., 3.},
    {1., 2., 3.},
    {1., 2., 3.}
  };
  double y1[3][3] = {
    {2., 4., 9.},
    {2., 4., 9.},
    {2., 4., 9}
  };

  double r1[3] = {3., 6., 12.};
  
  t._e = t1;
  y._e = y1;
  
  res = eval(*fooF, t, y);
  
  for(int i=0; i<9;++i){
    assert(res._e[i] == r1[i%3]);
  }

  double t2[2][2] = {
    {0., 0.},
    {0., 0.}
  };

  double y2[3][3] = {
    {0., 0., 0.},
    {0., 0., 0.},
    {0., 0., 0.}
  };

  t = initMatrix(t, 3, 3);
  y = initMatrix(y, 2, 2);

  t._e = t2;
  y._e = y2; 

  double r2[0] = {};

  res = eval(*fooF, t, y);
  
  for(int i=0; i<res.cols*res.rows; ++i){
    assert(res._e[i] == 0);
  }

  printf("numerics::DGE::eval is working.\n");
}

TEST testodeRK34(){
  matrixD res;
  vector t = initVec(t, 2);
  t._e[0] =  0;
  t._e[1] =  5;
  res = initMatrix(res, (int)5/(1./100), 2);
  vector y = initVec(y, 1);
  y._e[0] = 1.;
  
  res = odeRK34(&expDGL, t, y, 1/100.);
  for(int i=0; i<res.rows; ++i){
    double ti = res._e[getIndex(i, 0, res.rows, res.cols)];
    double yi = res._e[getIndex(i, 1, res.rows, res.cols)];
    assert(round_(yi, 5) == round_(exp(ti), 5));
  }
  printf("numerics::DGE:ordeRK34 is working.\n");
}

TEST testDGE(){
  testMeshgrid();
  testEval();
  testodeRK34();

  printf("numerics::DGE is working.\n");
}

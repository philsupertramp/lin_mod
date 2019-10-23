/**
 * File              : main.c
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 03.10.2019
 * Last Modified Date: 22.10.2019
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
#include <stdio.h>
#include <stdlib.h>

#include "lib/source.h"
#include "lib/numerics/examples.h"
#define DEBUG 0

double foo2(double i){
  return 0.100 * pow_(i, 2);
}
double foo(double i){
  return 0.12 * pow_(i, 2);
}


void (*Funs[2])(double i);

int main(){
  int ind = 0;
  matrixD res;
  vector t = initVec(t, 2);
  t._e[0] =   0;
  t._e[1] = 250;
  res = initMatrix(res, (int)250/(1./100), 3);
  
  
  void calcAndPlot(double startVal){
  vector y = initVec(y, 1);
  y._e[0] = startVal;
  matrixD result = odeEulerExp(&logGrowth, t, y, 1/100.);
  vector dt = initVec(dt, result.rows);
  vector dy = initVec(dy, result.rows); // bc. I know it's just a single value
  printf("GOOD\n");
  for(int i=0;i<result.rows;++i){
    for(int j=0;j<result.cols;++j){
      if(j==0){
        res._e[getIndex(i, 0, res.rows, res.cols)] = result._e[getIndex(i, 0, result.rows, result.cols)];
      }
      else {
        res._e[getIndex(i, j + ind, res.rows, res.cols)] = result._e[getIndex(i, j, result.rows, result.cols)];
      }
    }
  }
  ind += 1; 

  //scatterPlot(dt._e, dy._e, dt.size, attrs);
  } 
  calcAndPlot(5);
  calcAndPlot(15);
  
  printMat(res);
  FILE *gnuplot = popen("gnuplot --persist", "w");
  char *title1 = "Startvalue:    5";
  char *title2 = "Startvalue:   15";
  char *plotNames[2] = {title1, title2};
  plotAttributes attrs = {"logarithm growth", "X", "Y", 0, 200, 0, "#008080", gnuplot: gnuplot, plotNames: plotNames};
  multiPlot(res, attrs);

  /*
   *
   *
  vector a, b;
  matrixD meshX, meshY;
  a = initVec(a, 5);
  b = initVec(b, 5);
  meshX = initMatrix(meshX, 5, 5);
  printf("Initialized\n");
  double cols[5] = {1., 2., 3., 4., 5.};
  double rows[5] = {0.5, 0.6, 0.7, 0.8, 0.9};

  assignVals(a._e, cols, 5);
  assignVals(b._e, rows, 5);
  printf("Assigned\n");
  printVec(a);
  printVec(b);
  meshgrid(a, b, meshX, meshY);
  printf("Grid built\n");
  printMat(meshX);
   *
  double *x, *y, *v;
  FILE *gnuplot2 = popen("gnuplot --persist", "w");
  
  vectorV funs;
  Funs[0] = foo;
  Funs[1] = foo2;

  funs = initVecV(funs, 2);
  assignValsV(funs, Funs);
  plotAttributes attrs1 = {"0.02  x²", "X", "Y", 0.5, 2, 0, "#708090", 1};
  plotAttributes attrs2 = {"0.2   x²", "X", "Y", 0.5, 2, 0, "#008080"};
  plotFun(foo, -100, 100, 0, 300, 1, attrs1, gnuplot1);
  plotFun(foo2, -100, 100, 0, 300, 1, attrs2, gnuplot2);
  pclose(gnuplot1);
  pclose(gnuplot2);
**/
  return 0;
}


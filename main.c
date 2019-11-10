/**
 * File              : main.c
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 03.10.2019
 * Last Modified Date: 10.11.2019
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
  t._e[0] = 0;
  t._e[1] = 5;
  res = initMatrix(res, (int)5/(1./100), 20);
  
  
  void calcAndPlot(double h){
    vector y = initVec(y, 1);
    y._e[0] = 1;
    matrixD result = odeRK34(&expDGL, t, y, h);
    vector err = initVec(err, result.rows);
    vector diff = initVec(err, result.rows);
    for(int i=0;i<res.rows;++i){
      double t = 0;
      for(int j=0;j<res.cols;++j){
        if(i>result.rows || j>result.cols){
          res._e[getIndex(i, j + ind, res.rows, res.cols)] = -0.;
        }
        else{
          if(j==0){
            t = result._e[getIndex(i, 0, result.rows, result.cols)];
            res._e[getIndex(i, j + ind, res.rows, res.cols)] = t;
            t = exp(t);
          }
          else {
            double yi = result._e[getIndex(i, j, result.rows, result.cols)];
            diff._e[i] = yi - t;
            res._e[getIndex(i, j + ind + 1, res.rows, res.cols)] = yi;
          }
        }
      }
    }
  
    err._e[ind] = norm_d(diff._e, diff.size, Inf);
    ind += 1;
   printVec(err); 

  }
  for(int i=10; i<=100; i+=10){
    calcAndPlot(1./i);
    printf("%d iterations left.\n", 10 - i/10);
  }
  
  FILE *gnuplot = popen("gnuplot --persist", "w");
  char *title1 = "Schrittweite:   1/10.";
  char *title2 = "Schrittweite:   1/20.";
  char *title3 = "Schrittweite:   1/30.";
  char *title4 = "Schrittweite:   1/40.";
  char *title5 = "Schrittweite:   1/50.";
  char *title6 = "Schrittweite:   1/60.";
  char *title7 = "Schrittweite:   1/70.";
  char *title8 = "Schrittweite:   1/80.";
  char *title9 = "Schrittweite:   1/90.";
  char *title10 = "Schrittweite:   1/100.";

  char *plotNames[10] = {title1, title2, title3, title4, title5, title6, title7, title8, title9, title10};
  plotAttributes attrs = {"exponential growth", "X", "Y", 0, 10, 0, "#008080", gnuplot: gnuplot, plotNames: plotNames};
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


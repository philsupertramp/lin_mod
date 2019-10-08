/**
 * File              : main.c
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 03.10.2019
 * Last Modified Date: 08.10.2019
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
#include <stdio.h>
#include <stdlib.h>

#include "lib/source.h"
#define DEBUG 0

double foo2(double i){
  return 0.100 * pow_(i, 2);
}
double foo(double i){
  return 0.12 * pow_(i, 2);
}
void (*Funs[2])(double i);

int main(){
  /*
  double *x, *y, *v;
  FILE *gnuplot1 = popen("gnuplot --persist", "w");
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


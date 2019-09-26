#include <stdio.h>
#include <stdlib.h>

#include "lib/matrix.h"
#include "lib/stat.h"
#include "lib/plot.h"
#include "lib/array.h"

#define DEBUG 0


int main(){
  double *x, *y, *v;
  int len = 10;
  x=allocArray(x, len);
  y=allocArray(y, len);
  double absatz[10] = {1585.,1819.,1647.,1496.,921.,1278.,1810.,1987.,1612.,1413.};
  double preis[10] = {12.5,10.,9.95,11.5,12.,10.,8.,9.,9.5,12.5};
  assignVals(x, absatz, len);
  assignVals(y, preis, len);
  printArray(x, len);
  printArray(y, len);
  printf("mean: \t%f\n", mean_d(x, 10));
  printf("cov: \t%f\n", cov_d(x,y,10));
  printf("var: \t%f\n", var_d(x,10));
  lmMod mod = lm_d(y,x,10);
  printf("lm: \tbeta_0=%f \tbeta_1=%f\n", mod.beta_0, mod.beta_1);
  printArray(mod.y_estimate, 10);
  plotAttributes attrs = {title: "Scatterplot", xAxis: "Absatz", yAxis: "Preis"};
  scatterPlot(x, y, 10, attrs);
  double ts = getExponent(100);
  printf("exp: %f\n", ts);
  return 0;
}


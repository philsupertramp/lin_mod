/**
 * File              : main.c
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 03.10.2019
 * Last Modified Date: 03.10.2019
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
#include <stdio.h>
#include <stdlib.h>

#include "lib/source.h"
#define DEBUG 0

double foo(double i){
  return pow_(1.53,2)*i/pow_(5.67+i, 2) * 1000;
}

int main(){
  double *x, *y, *v;
  plotAttributes attrs = {"test", "X", "Y", 0.5, 2};
  plotFun(foo, 0, 100, 0, 300, 0.1, attrs);
  return 0;
}


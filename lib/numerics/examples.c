/**
 * File              : examples.c
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 21.10.2019
 * Last Modified Date: 09.11.2019
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
#include "examples.h"

double logGrowth(double ti, double yi){
  return 1/5. * (1 - yi/10.);
}

double exponentialGrowth(double ti, double yi){
  double n0 = .10;
  double t0 = 200;
  double lambda = 0.5;
  return n0 * exp(lambda * (ti - t0));
}
double expDGL(double ti, double yi){
  return yi;
}

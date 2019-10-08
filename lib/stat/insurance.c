/**
 * File              : insurance.c
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 08.10.2019
 * Last Modified Date: 08.10.2019
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
#include "insurance.h"
#include "stat.h"
#include <math.h>

double compoundingFactor(double i){
  return 1 + i;
}
double discountFactor(double i){
  return 1./(1.+i);
}
double fundamentalValue(interest Z){
  return Z.K_N * pow_(1 + Z.i, -Z.n);
}
double endValue(interest Z){
  return Z.K_0 * pow_(1 + Z.i, Z.n);
}
double termInPeriods(interest Z){
  return (log(Z.K_N) - log(Z.K_0)) / log(compoundingFactor(Z.i));
}
double fundamentalValueOfAnnuityInAdvance(interest Z){
  double discount = discountFactor(Z.i);
  return (1-pow_(discount, Z.n))/(1-discount);
}
double endValueOfAnnuityInAdvance(interest Z){
  double compFactor = compoundingFactor(Z.i);
  double discount = discountFactor(Z.i);
  return (pow_(compFactor, Z.n) - 1)/(1 - discount);
}
double fundamentalValueOfAnnuityInArrear(interest Z){
  double discount = discountFactor(Z.i);
  return (1-pow_(discount, Z.n))/Z.i;
}
double endValueOfAnnuityInArrear(interest Z){
  double compFactor = compoundingFactor(Z.i);
  return fundamentalValueOfAnnuityInArrear(Z) * pow_(compFactor, Z.n);
}


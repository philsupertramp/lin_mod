/**
 * File              : finance.c
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 20.04.2020
 * Last Modified Date: 20.04.2020
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
#include "finance.h"


double interest_d(double val, double interest){
  double a = val * interest;
  return val + a;  
}


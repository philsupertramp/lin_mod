/**
 * File              : stat.c
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 28.09.2019
 * Last Modified Date: 08.10.2019
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
/*
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
#ifndef DEBUG
#define DEBUG 0
#include <stdio.h>
#include <math.h>

#include "stat.h"
#include "../array.h"


double round_(double x, int precision){
  int prec = pow_(10, precision);
  int lastDigit = abs_((int)(x*prec*10) % 10);
  return ((int)(x * prec) + (lastDigit > 0 && lastDigit >= 5 ? 1 : 0) * (x>0?1:-1))/(double)prec;
}

double abs_(double x){
  if(x<0.)
    return x*(-1.);
  return x;
}
double pow_(double x, int p){
  if(p==0) return 1;
  if(p<0) return 1/pow_(x, -1*p);
  double result = x;
  for(int i=0; i<p-1;i++)
    result = result * x;
  return result;
}

double mean_d(double *x, int size){
  double result = 0;
  for(int i=0; i<size;i++)
    result = result + x[i];
  return result/size;
}

double cov_d(double *x, double *y, int size){
  double sum = 0.;
  for(int i=0; i<size; i++)
    sum = sum + x[i] * y[i];
  double mean_val = mean_d(x, size) * mean_d(y, size);
  return (1./(size-1) * sum) - (size/(size-1.) * mean_val);
}

double var_d(double *x, int size){
  double x_mean = mean_d(x, size);
  double sum = 0.;
  for(int i=0; i<size; i++)
    sum = sum + pow_(x[i], 2);
  return abs_((1./(size-1) * sum) - (size/(size-1.) * pow_(mean_d(x,size), 2)));
}

lmMod lm_d(double *x, double *y, int size){
  double covar = cov_d(x,y,size);
  double variance = var_d(x, size);

  double beta_1 = covar/variance;
  double beta_0 = mean_d(y, size) - beta_1 * mean_d(x, size);

  double *estimate, *residuals;
  estimate = allocArray(estimate, size);
  residuals = allocArray(residuals, size);
  for(int i=0; i<size; i++){
    estimate[i] = beta_0 + beta_1 * x[i];
    residuals[i] = y[i] - estimate[i];
  }
  lmMod mod = {.beta_1=beta_1, .beta_0=beta_0, .y_estimate=estimate, .residuals=residuals};
  return mod;
}


double coefficientOfDetermination(vector *y, vector *yHat){
  double varY = var_d(y->_e, y->size);
  double varYHat = var_d(yHat->_e, yHat->size);
  return varY/varYHat;
}

double min_d(double *x, int size){
  if(size<1){
    return NAN;
  }
  double minimum = x[0];
  for(int i=1; i<size;i++){
    if(x[i] < minimum){
      minimum = x[i];
    }
  }
  return minimum;
}

double max_d(double *x, int size){
  if(size<1){
    return NAN;
  }
  double maximum = x[0];
  for(int i=1; i<size;i++){
    if(x[i]>maximum){
      maximum = x[i];
    }
  }
  return maximum;
}

double getExponent(double x){
  double exponent = 1;
  while(abs_(x/pow_(10, exponent)) > 1){
    exponent = exponent + 1;
  }
  return exponent;
}

#endif

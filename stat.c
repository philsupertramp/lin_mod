#ifndef DEBUG
#define DEBUG 0
#include <stdio.h>
#include <math.h>

#include "stat.h"

double abs_(double x){
  if(x<0.)
    return x*(-1.);
  return x;
}
double pow_(double x, int p){
  double result = x;
  for(int i=0; i<p-1;i++)
    result = result * x;
  return result;
}

double mean(vector *x){
  double result = 0.;
  int len = vec_total(x);
  for(int i=0; i<len;i++){
    result = result + *vec_get(x, i);
  }
  result = (double)result/len;
  return result;
}

double mean_d(double *x, int size){
  double result = 0;
#if DEBUG
  printf("len: %d\n", size);
#endif
  for(int i=0; i<size;i++)
    result = result + x[i];
  return result/size;
}

double cov(vector *x, vector *y){
  int len = vec_total(x);
  int leny = vec_total(y);
  if(len != leny) return 0;
  double sum = 0.;
  for(int i=0; i<len; i++){
    sum = sum + (*vec_get(x, i) * *vec_get(y, i));
  }
  double mean_val = mean(x) * mean(y);
  return (1./(len-1) * sum) - (len/(len-1.) * mean_val);
}

double cov_d(double *x, double *y, int size){
  double sum = 0.;
  for(int i=0; i<size; i++)
    sum = sum + x[i] * y[i];
  double mean_val = mean_d(x, size) * mean_d(y, size);
  return (1./(size-1) * sum) - (size/(size-1.) * mean_val);
}

double var(vector *x){
  double x_mean = mean(x);
  int len = vec_total(x);
  double sum = 0.;
  for(int i = 0; i<len; i++){
    sum = sum + pow_(*vec_get(x,i),2);
  }
  return abs_((1./(len-1) * sum) - (len/(len-1.) * pow_(mean(x),2)));
}

double var_d(double *x, int size){
  double x_mean = mean_d(x, size);
  double sum = 0.;
  for(int i=0; i<size; i++)
    sum = sum + pow_(x[i], 2);
  return abs_((1./(size-1) * sum) - (size/(size-1.) * pow_(mean_d(x,size), 2)));
}

vector lm(vector *x, vector *y){
  double covariance = cov(x, y);
  double variance = var(x);

  double beta_1 = covariance/variance;
  double beta_0 = mean(y) - beta_1 * mean(x);
  
  vector result;
  vec_init(&result);
  vec_add(&result, &beta_0);
  vec_add(&result, &beta_1);
  return result;
}

lmMod lm_d(double *x, double *y, int size){
  double covar = cov_d(x,y,size);
  double variance = var_d(x, size);

  double beta_1 = covar/variance;
  double beta_0 = mean_d(y, size) - beta_1 * mean_d(x, size);
  
  lmMod mod = {.beta_1=beta_1, .beta_0=beta_0};
  return mod;
}

double coefficientOfDetermination(vector *y, vector *yHat){
  double varY = var(y);
  double varYHat = var(yHat);
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

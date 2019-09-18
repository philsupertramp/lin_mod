#ifndef DEBUG
#define DEBUG 1
#include <stdio.h>

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

double var(vector *x){
  double x_mean = mean(x);
  int len = vec_total(x);
  double sum = 0.;
  for(int i = 0; i<len; i++){
    sum = sum + pow_(*vec_get(x,i),2);
  }
  return abs_((1./(len-1) * sum) - (len/(len-1.) * pow_(mean(x),2)));
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

double coefficientOfDetermination(vector *y, vector *yHat){
  double varY = var(y);
  double varYHat = var(yHat);
  return varY/varYHat;
}

#endif

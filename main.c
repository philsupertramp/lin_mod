#include <stdio.h>

#include "vector.h"
#include "stat.h"

int main(){
  vector x, y;
  vec_init(&x);
  vec_init(&y);
  double x_1  = 30;
  double x_2  = 20;
  double x_3  = 60;
  double x_4  = 80;
  double x_5  = 40;
  double x_6  = 50;
  double x_7  = 60;
  double x_8  = 30;
  double x_9  = 70;
  double x_10 = 60;

  double y_1  = 73;
  double y_2  = 50;
  double y_3  = 128;
  double y_4  = 170;
  double y_5  = 87;
  double y_6  = 108;
  double y_7  = 135;
  double y_8  = 69;
  double y_9  = 148;
  double y_10 = 132;
  
  vec_add(&x, &x_1);
  vec_add(&x, &x_2);
  vec_add(&x, &x_3);
  vec_add(&x, &x_4);
  vec_add(&x, &x_5);
  vec_add(&x, &x_6);
  vec_add(&x, &x_7);
  vec_add(&x, &x_8);
  vec_add(&x, &x_9);
  vec_add(&x, &x_10);
  
  vec_add(&y, &y_1);
  vec_add(&y, &y_2);
  vec_add(&y, &y_3);
  vec_add(&y, &y_4);
  vec_add(&y, &y_5);
  vec_add(&y, &y_6);
  vec_add(&y, &y_7);
  vec_add(&y, &y_8);
  vec_add(&y, &y_9);
  vec_add(&y, &y_10);
  
  double meanValX =  mean(&x);
  double meanValY =  mean(&y);
  double covVar = cov(&x, &y);
  double varVarX = var(&x);
  double varVarY = var(&y);
  printf("X: mean= %f, var: %f\n", meanValX, varVarX);
  printf("Y: mean= %f, var: %f\n", meanValY, varVarY);
  printf("cov val= %f\n", covVar);
  vector lm_ = lm(&x, &y);
  printf("lm:\n beta_0 = %f, beta_1 = %f\n", *vec_get(&lm_, 0), *vec_get(&lm_, 1));
  return 0;
}


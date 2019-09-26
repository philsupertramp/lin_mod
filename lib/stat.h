#ifndef STAT_H
#define STAT_H

#include "matrix.h"
typedef struct lmMod {
  double beta_0;
  double beta_1;
  double *y_estimate;
  double *residuals;
} lmMod;

double round_(double, int);
double abs_(double);
double pow_(double, int);
double min_d(double *, int);
double max_d(double *, int);
double mean(vector *);
double mean_d(double *, int);
double cov(vector *, vector *);
double cov_d(double *, double *, int);
double var(vector *);
double var_d(double *, int);
vector lm(vector*, vector*);
lmMod lm_d(double*, double*, int);
double coefficientOfDetermination(vector*, vector*);
double getExponent(double);

#endif

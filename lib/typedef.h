/**
 * File              : typedef.h
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 08.10.2019
 * Last Modified Date: 09.11.2019
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
#ifndef TYPEDEF_H
#define TYPEDEF_H

#include <stdio.h>

#define u_int unsigned int
/* stat */
typedef struct interest {
  double i;
  double n;
  double K_0;
  double K_N;
  double R;
}interest;

typedef struct lmMod {
  double beta_0;
  double beta_1;
  double *y_estimate;
  double *residuals;
} lmMod;

/* plot */
typedef struct boundary {
  double min;
  double max;
} boundary;
typedef struct plotAttributes {
  char title[50];
  char xAxis[50];
  char yAxis[50];
  int pointStrength;
  int lineStrength;
  u_int isStatPlot;
  char color[7];
  u_int isFirstPlot;
  FILE *gnuplot;
  char **plotNames;
} plotAttributes;

/* common objs */
typedef struct matrixD {
  double *_e;
  u_int rows;
  u_int cols;
} matrixD;
typedef struct matrixV {
  void *_e;
  u_int rows;
  u_int cols;
} matrixV;
typedef struct vectorV {
  void *_e;
  u_int size;
} vectorV;
typedef struct vector {
  double *_e;
  u_int size;
} vector;

typedef enum { Inf, Two, One } P_NORM;
#endif

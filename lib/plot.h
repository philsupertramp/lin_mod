#ifndef PLOT_H
#define PLOT_H

#include "stat.h"

typedef struct boundary {
  double min;
  double max;
} boundary;
typedef struct plotAttributes {
  char title[50];
  char xAxis[50];
  char yAxis[50];
} plotAttributes;


void scatterPlot(double *, double *, int, plotAttributes);
boundary getBoundaries(double *, int);
double getExponent(double);

#endif

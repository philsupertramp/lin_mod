#ifndef STAT_H
#define STAT_H

#include "vector.h"

double abs_(double);
double pow_(double, int);
double mean(vector *);
double cov(vector *, vector *);
double var(vector *);
vector lm(vector*, vector*);

#endif

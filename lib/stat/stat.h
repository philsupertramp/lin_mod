/**
 * File              : stat.h
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 28.09.2019
 * Last Modified Date: 08.10.2019
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
/**
 * lib/stat.h
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
#ifndef STAT_H
#define STAT_H

#include "../matrix.h"


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

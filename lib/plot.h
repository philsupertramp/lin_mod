/**
 * File              : plot.h
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 28.09.2019
 * Last Modified Date: 03.10.2019
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
/**
 * lib/plot.h
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
  int pointStrength;
  int lineStrength;
  u_int isStatPlot;
} plotAttributes;


void writeAttributes(plotAttributes, FILE *);
void scatterPlot(double *, double *, int, plotAttributes);
void plotFun(double (*fun)(double), int, int, int, int, double, plotAttributes);
boundary getBoundaries(double *, int);
double getExponent(double);

#endif

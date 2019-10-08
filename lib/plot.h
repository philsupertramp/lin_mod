/**
 * File              : plot.h
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 28.09.2019
 * Last Modified Date: 08.10.2019
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

#include "stat/stat.h"
#include "matrix.h"

void writeAttributes(plotAttributes, FILE *);
void scatterPlot(double *, double *, int, plotAttributes);
void plotFun(double (*fun)(double), int, int, int, int, double, plotAttributes, FILE*);
void genPlotData(matrixD);
boundary getBoundaries(double *, int);
double getExponent(double);


#endif

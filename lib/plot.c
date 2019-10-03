/**
 * File              : plot.c
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 28.09.2019
 * Last Modified Date: 03.10.2019
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
/**
 * lib/plot.c
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
#include <string.h>
#include <stdio.h>

#include "plot.h"

void writeAttributes(plotAttributes attrs, FILE *gnuplot){
  if(attrs.title){
    char titleExtension[105];
    if(attrs.xAxis && attrs.yAxis && attrs.isStatPlot){
      strcpy(titleExtension, attrs.xAxis);
      strcat(strcat(titleExtension, " vs. "), attrs.yAxis);
    }
    fprintf(gnuplot, "set title '%s", attrs.title); 
    if(attrs.isStatPlot){
      fprintf(gnuplot, "%s", titleExtension);
    }
    fprintf(gnuplot, "'\n");
  }
  if(attrs.xAxis){
    fprintf(gnuplot, "set xlabel '%s'\n", attrs.xAxis);
  }
  if(attrs.yAxis){
    fprintf(gnuplot, "set ylabel '%s'\n", attrs.yAxis);
  }
}

void scatterPlot(double *x, double *y, int len, plotAttributes attrs){
  /*
   * generates a scatter plot
   */
  
  boundary bX, bY;
  bX = getBoundaries(x, len);
  bY = getBoundaries(y, len);
  
  FILE *gnuplot = popen("gnuplot --persist", "w");
  
  writeAttributes(attrs, gnuplot);
  
  fprintf(gnuplot, "plot [%f:%f] [%f:%f] '-' with points pt 7\n", bX.min, bX.max, bY.min, bY.max);
  for(int i=0; i<len; i++){
    fprintf(gnuplot, "%g %g\n", x[i], y[i]);
  }
  fprintf(gnuplot, "e\n");
  
  pclose(gnuplot);
}

void plotFun(double (*fun)(double), int startX, int endX, int startY, int endY, double stepSize, plotAttributes attrs){
  // Plots a given function fun
  // in the range x = [startX, endX] y = [startY, endY] with step size stepSize
  
  vector X, Y;
  int size =  ((int)(endX - startX)/stepSize) + 2;
  printf("%d\n", size);
  X = initVec(X, size);
  Y = initVec(Y, size);
  register int iter = 0;
  for(double i=startX-stepSize; i<=endX && iter < size; i+=stepSize){
    X._e[iter] = i;
    Y._e[iter] = fun(i);
    iter += 1;
  }
#if DEBUG
  printVec(X);
  printVec(Y);
#endif
  FILE *gnuplot = popen("gnuplot --persist", "w");
  writeAttributes(attrs, gnuplot);

  fprintf(gnuplot, "set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth %d pointtype 7 pointsize %d\n", attrs.lineStrength, attrs.pointStrength);

  fprintf(gnuplot, "plot [%d:%d] [%d:%d] '-' with linespoints linestyle 1\n", startX, endX, startY, endY);
  for(int i=0;i<size; ++i){
    fprintf(gnuplot, "%g %g\n", X._e[i], Y._e[i]);
  }
  fprintf(gnuplot, "e\n");
  pclose(gnuplot);
}

boundary getBoundaries(double *x, int size){
  /*
   * determines the boundaries of a array
   * returns: boundary(min, max)
   */
  double startX = min_d(x, size);
  //startX = startX - pow_(10, getExponent(startX) - 1); 
  double endX = max_d(x, size);
  //endX = endX - pow_(10, getExponent(endX) - 1);
  boundary bond = {min: startX, max: endX};
  return bond; 
}


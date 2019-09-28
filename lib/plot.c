/**
 * File              : plot.c
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 28.09.2019
 * Last Modified Date: 28.09.2019
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

void scatterPlot(double *x, double *y, int len, plotAttributes attrs){
  /*
   * generates a scatter plot
   */
  
  boundary bX, bY;
  bX = getBoundaries(x, len);
  bY = getBoundaries(y, len);
  
  FILE *gnuplot = popen("gnuplot --persist", "w");
  if(attrs.title){
    char titleExtension[105];
    if(attrs.xAxis && attrs.yAxis){
      strcpy(titleExtension, attrs.xAxis);
      strcat(strcat(titleExtension, " vs. "), attrs.yAxis);
    }
    fprintf(gnuplot, "set title '%s %s'\n", attrs.title, (titleExtension) ? titleExtension : ""); 
  }
  if(attrs.xAxis){
    fprintf(gnuplot, "set xlabel '%s'\n", attrs.xAxis);
  }
  if(attrs.yAxis){
    fprintf(gnuplot, "set ylabel '%s'\n", attrs.yAxis);
  }
  
  fprintf(gnuplot, "plot [%f:%f] [%f:%f] '-' with points pt 7\n", bX.min, bX.max, bY.min, bY.max);
  for(int i=0; i<len; i++){
    fprintf(gnuplot, "%g %g\n", x[i], y[i]);
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


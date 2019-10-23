/**
 * File              : plot.c
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 28.09.2019
 * Last Modified Date: 22.10.2019
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
#include <math.h>
#include <time.h>

#include "plot.h"
#include "numerics/dge.h"
#include "utils.h"


void writeAttributes(plotAttributes attrs){
  FILE *gnuplot = attrs.gnuplot;
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
  
  writeAttributes(attrs);
  
  fprintf(attrs.gnuplot, "plot [%f:%f] [%f:%f] '-' with points pt 7\n", bX.min, bX.max, bY.min, bY.max);
  for(int i=0; i<len; i++){
    fprintf(attrs.gnuplot, "%g %g\n", x[i], y[i]);
  }
  fprintf(attrs.gnuplot, "e\n");
  
  pclose(attrs.gnuplot);
}

void multiPlot(matrixD mat, plotAttributes attrs){
  writeAttributes(attrs);
  
  time_t now = time(NULL);
  FILE* file = fopen("multiPlot_data.txt", "w");
  for(int j=0; j<mat.rows; ++j){
    for(int i=0; i<mat.cols; ++i){
      fprintf(file, "%g", mat._e[getIndex(j, i, mat.rows, mat.cols)]);
      fprintf(file, i == mat.cols - 1 ? " " : ", ");
    }
    fprintf(file, "\n");
  }
  for(int i=0; i<2; ++i){
    printf("%s\n", attrs.plotNames[i]);
  }
  for(int i=1; i<mat.cols; ++i){
    fprintf(attrs.gnuplot, i == 1 ? "plot [0:250] [0:20] " : "");
    fprintf(attrs.gnuplot, "'multiPlot_data.txt' using %d:%d with lines title '%s'", 1, i + 1, attrs.plotNames[i-1]);
    fprintf(attrs.gnuplot, i == mat.cols - 1 ? "\n" : ",");

  }
  fprintf(attrs.gnuplot, "\n");
}


void addDataToPlot(vector X, vector Y, int size, FILE *gnuplot){

  for(int i=0;i<size; ++i){
    fprintf(gnuplot, "%g %g\n", X._e[i], Y._e[i]);
  }
}
void plotFun(double (*fun)(double), int startX, int endX, int startY, int endY, double stepSize, plotAttributes attrs){
  // Plots a given function fun
  // in the range x = [startX, endX] y = [startY, endY] with step size stepSize
  FILE *gnuplot = attrs.gnuplot;
  
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
  writeAttributes(attrs);

  // configure
  fprintf(gnuplot, "set style line 1 linecolor rgb '%s' linetype 1 ", attrs.color ? attrs.color : "#4682B4");
  fprintf(gnuplot, "linewidth %d pointtype 7 ", attrs.lineStrength | 1);
  fprintf(gnuplot, "pointsize %d\n", attrs.pointStrength | 1);

  fprintf(gnuplot, "plot [%d:%d] [%d:%d] '-' with linespoints linestyle 1\n", startX, endX, startY, endY);
  addDataToPlot(X, Y, size, gnuplot);
  fprintf(gnuplot, "e\n");
  //pclose(gnuplot);
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
void plotSlopeField(double (*fun)(double, double), vector t, vector y, double s, plotAttributes attrs){
  matrixD ti, yi;
  FILE *gnuplot = attrs.gnuplot;
  meshgrid(t, y, ti, yi);

  double min_val[2] = {(t._e[t.size - 1] - t._e[0])/t.size, (y._e[y.size - 1] - y._e[0])/y.size};
  double scal = s * min_d(min_val, 2);
  matrixD evalSimpleFun(double (*foo)(double xi), matrixD x){
    matrixD result = initMatrix(result, x.cols, x.rows);
    for(int i=0; i<x.cols; ++i){
      for(int j=0; j<x.rows; ++j){
        int index = getIndex(i, j, x.cols, x.rows);
        result._e[index] = foo(x._e[index]);
      }
    }
    return result;
  }

  double normDyDt(double dyi){
    return sqrt(dyi * dyi + 1);
  }
  double dtF(double normdydti){
    return scal*normdydti;
  }
  double dyF(double dyi, double dti){
    return scal * dyi/dti;
  }

  matrixD dy = eval(fun, ti, yi); 
  matrixD normdydt = evalSimpleFun(normDyDt, dy);
  matrixD dt = evalSimpleFun(dtF, invertMatrixD(normdydt)); // matrix

  

  
  dy = eval(dyF, dy, normdydt);

  writeAttributes(attrs);

  // configure
  fprintf(gnuplot, "set style line 1 linecolor rgb '%s' linetype 1 ", attrs.color ? attrs.color : "#4682B4");
  fprintf(gnuplot, "linewidth %d pointtype 7 ", attrs.lineStrength | 1);
  fprintf(gnuplot, "pointsize %d\n", attrs.pointStrength | 1);

  /*
  fprintf(gnuplot, "plot [%d:%d] [%d:%d] '-' with linespoints linestyle 1\n", startX, endX, startY, endY);
  addDataToPlot(X, Y, size, gnuplot);
  fprintf(gnuplot, "e\n");
*/
  char *point_cmd = "replot '-'\n";
  char *line_cmd = "replot '-' with linespoints linestyle 1\n";
  for(int i=0;i<t.size;++i){
    for(int j=0;j<y.size;++j){
      int ij = getIndex(i, j, ti.cols, ti.rows);
      double cur_t = ti._e[ij];
      double cur_y = yi._e[ij];
      if(i == 0 && j == 0){
      // center point
        fprintf(gnuplot, "plot '-'\n");
      }
      else {
        fprintf(gnuplot, point_cmd);
      }
      fprintf(gnuplot, "%f, %f\n", cur_t, cur_y);
      fprintf(gnuplot, "e\n");

      // slope
      fprintf(gnuplot, line_cmd);
      fprintf(gnuplot, "%f, %f\n", cur_t - dt._e[ij], cur_t + dt._e[ij]);
      fprintf(gnuplot, "%f, %f\n", cur_y - dy._e[ij], cur_y + dy._e[ij]);
      fprintf(gnuplot, "e\n");
    }
  }
}


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


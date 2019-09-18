#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "stat.h"

#define DEBUG 1
void printArray(double *vec, int size);
double *allocArray(double *vec, int size);
int main(){
  double *x, *y;
  int len = 10;
  x=allocArray(x, len);
  y=allocArray(y, len);
  double absatz[10] = {1585.,1819.,1647.,1496.,921.,1278.,1810.,1987.,1612.,1413.};
  double preis[10] = {12.5,10.,9.95,11.5,12.,10.,8.,9.,9.5,12.5};
  for(int i=0; i<len;i++){
    *(x+i) = absatz[i];
    *(y+i) = preis[i];
  }
  printArray(x, len);
  printArray(y, len);

  FILE *gnuplot = popen("gnuplot", "w");
  fprintf(gnuplot, "plot '-'\n"); 
  for(int i=0; i<len; i++){
    fprintf(gnuplot, "%g %g\n", x[i], y[i]);
  }
  fprintf(gnuplot, "e\n");
  fflush(gnuplot);
}


double *allocArray(double *vec, int size){
#if DEBUG
  printf("DEBUG::pre-allocArray size: %d \t|\t vec location: %x\n", sizeof(&vec), vec);
#endif
  vec = calloc(size, sizeof(double ));
#if DEBUG
  printf("DEBUG::post-allocArray size: %d \t|\t vec location: %x\n", sizeof(&vec), vec);
#endif
  return vec;
}

void printArray(double *vec, int size){
  printf("vec: [\n");
  for(int i=0; i<size; i++){
    printf("\t%f\n", vec[i]);
  }
  printf("]\n");
}

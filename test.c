#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "stat.h"

#define DEBUG 1
void printArray(double *vec, int size);
double *allocArray(double *vec, int size);
int main(){
  double a1 = 1.;
  double *q;
  q = allocArray(q, 5);
#if DEBUG
  printArray(q, 5);
#endif
  double s[5] = {2.,3.,4.,5.,6.};
  for(int i=0; i<5;i++){
    *(q+i) = s[i];
  }
#if DEBUG
  printArray(q, 5);
#endif
  allocArray(q, 6);
  *(q+5) = 7.;
#if DEBUG
  printArray(q, 6);
#endif
  free(q);
  return 0;
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

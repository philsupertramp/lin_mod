#include <stdlib.h>
#include <stdio.h>

#include "array.h"

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
  for(int i=0; i<size; i++) printf("\t%f\n", vec[i]);  
  printf("]\n");
}

void assignVals(double *vec, double vals[], int len){
  for(int i=0; i<len;i++) *(vec+i) = vals[i];
}


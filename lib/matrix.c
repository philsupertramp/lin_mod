#include <stdarg.h>
#include <stdlib.h>

#include "matrix.h"


void mat_init(int count, ...){
  va_list args;
  int size = 2 * INIT_STORAGE_SIZE;
  matrix *mat;
  va_start(args, count);
  if(count > 1) mat = va_arg(args, matrix*);
  if(count > 2) size = va_arg(args, int);
  
  mat->rows = 0;
  mat->columns = 0;
  mat->items = malloc(sizeof(double*) * size);
}

int mat_col(matrix *mat){
  return mat->columns;
}
int mat_row(matrix *mat){
  return mat->rows;
}

static void mat_resize(matrix *mat, int newSize){

}

void mat_add(matrix *mat, vector *vec){

}

void mat_set(matrix *mat, int col, int row, double *item){

}

vector *mat_get(matrix *mat, int index){

}

void mat_delete(matrix *mat, int index){

}

void mat_free(matrix* mat){

}


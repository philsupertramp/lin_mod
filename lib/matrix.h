#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

typedef struct matrix {
  vector **items;
  int columns;
  int rows;
  int storageSize;
} matrix;

void mat_init(int, ...);
int mat_col(matrix *);
int mat_row(matrix *);
static void mat_resize(matrix *, int);
void mat_add(matrix *, vector *);
void mat_set(matrix *, int, int, double*);
vector *mat_get(matrix *, int);
void mat_delete(matrix *, int);
void mat_free(matrix *);

#endif

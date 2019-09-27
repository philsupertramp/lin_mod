#ifndef MATRIX_H
#define MATRIX_H

#include "array.h"

//#include "vector.h"
#define u_int unsigned int

typedef struct matrix {
  double *_e;
  u_int rows;
  u_int cols;
} matrix;
typedef struct vector {
  double *_e;
  u_int size;
} vector;
//#define vector double *

matrix initMatrix(matrix, int, int);
vector mVecMultiplication(matrix mat, vector vec);
vector initVec(vector, unsigned int);
void printVec(vector);
void printMat(matrix);
int getIndex(int, int, u_int, u_int);
matrix mScalarMult(matrix, double);
matrix mMatMult(matrix, matrix);

/*
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
*/
#endif

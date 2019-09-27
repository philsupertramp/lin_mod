#ifndef TEST_ARRAY_H
#define TEST_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../lib/array.h"


void arrayAllocTest();
void arrayAssignTest();
void arrayFreeTest();

void testArray(){
  arrayAllocTest();
  arrayAssignTest();
}

void arrayAllocTest(){
  double *q = NULL;
  q = allocArray(q, 5);
  assert(q != NULL);
  free(q);
  printf("array::allocArray working.\n");
}

void arrayAssignTest(){
  double *q;
  q = allocArray(q, 2);
  q[0] = 0;
  q[1] = 0;
  double s[3] = {1., 2., 3.};
  q = allocArray(q, 3);
  assignVals(q, s, 3);
  assert(q[2] == 3);
  free(q);
  printf("array::assignVals working.\n");
}

#endif

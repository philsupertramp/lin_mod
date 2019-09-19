#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../lib/array.h"


void arrayAllocTest();
void arrayAssignTest();
void arrayFreeTest();
void testArray();

void testArray(){
  arrayAllocTest();
  arrayAssignTest();
  arrayFreeTest();
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

void arrayFreeTest(){
  double *q;
  q = allocArray(q, 1);
  *(q) = 1;
  const double *preAddr = q;
  assert(q == preAddr);
  assert(q[0] == 1);
  free(q);
  q = NULL;
  q = allocArray(q, 2);
  *(q) = 2;
  *(q+1) = 3;
  assert(q != preAddr);
  assert(q[0] == 2);
  assert(q[1] == 3);
#if DEBUG
  printf("%x != %x\n", preAddr, q);
#endif
  free(q);
  printf("array::free working.\n");
}


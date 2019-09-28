/**
 * File              : test_array.h
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 28.09.2019
 * Last Modified Date: 28.09.2019
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
/**
 * tests/test_array.h
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

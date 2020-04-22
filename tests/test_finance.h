/**
 * File              : test_finance.h
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 20.04.2020
 * Last Modified Date: 20.04.2020
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
#ifndef TEST_FINANCE_H
#define TEST_FINANCE_H

#include "../lib/stat/finance.h"
#include "../lib/source.h"

#include <stdio.h>
#include <assert.h>


void test_interest_d(){
  double a = 1.0;
  assert(interest_d(a, 0.0) == a);
  printf("stat::finance::interest_d is working.\n");
}

void testFinance(){
  
  printf("stat::finance is working.\n");
}

#endif // TEST_FINANCE_H

/**
 * File              : test_insurance.h
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 08.10.2019
 * Last Modified Date: 08.10.2019
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
#ifndef TEST_INSURANCE_H
#define TEST_INSURANCE_H

#define TEST void

#include "../lib/source.h"

#include <stdio.h>
#include <assert.h>
interest A = {0.028, 20, K_0: 18187.61, K_N: 31596.42, R: 1200};

TEST testCompoundingFactor(){
  assert(compoundingFactor(0.028) == 1.028);
  printf("stat::insurance::compundingFactor is working.\n"); 
}
TEST testDiscountFactor(){
  assert(round_(discountFactor(0.028), 4) == 0.9728);
  printf("stat::insurance::discountFactor is working.\n"); 
}
TEST testFundamentalValue(){
  double fundValue = fundamentalValue(A);
  assert(round_(fundValue, 2) == A.K_0);
  printf("stat::insurance::fundamentalValue is working.\n"); 
}
TEST testEndValue(){
  double endVal = endValue(A);
  assert(round_(endVal, 2) == A.K_N);
  printf("stat::insurance::endValue is working.\n"); 
}
TEST testFundamentalValueOfAnnuityInAdvance(){
  double fundValue = fundamentalValueOfAnnuityInAdvance(A) * A.R;
  assert(round_(fundValue, 2) == round_(15.580719 * 1200., 2));
  printf("stat::insurance::fundamentalValueOfAnnuityInAdvance is working.\n");
}
TEST testEndValueOfAnnuityInAdvance(){
  double endVal = endValueOfAnnuityInAdvance(A) * A.R;
  assert(round_(endVal, 2) == 32481.12);
  printf("stat::insurance::endValueOfAnnuityInAdvance is working.\n");
}

TEST testFundamentalValueOfAnnuityInArrear(){
  double fundValue = fundamentalValueOfAnnuityInArrear(A) * A.R;
  assert(round_(fundValue, 2) == 18187.61);
  printf("stat::insurance::fundamentalValueOfAnnuityInArrear is working.\n");
}

TEST testEndValueOfAnnuityInArrear(){
  double endVal = endValueOfAnnuityInArrear(A) * A.R;
  assert(round_(endVal, 2) == 31596.42);
  printf("stat::insurance::endValueOfAnnuityInArrear is working.\n");
}

TEST testInsurance(){
  testCompoundingFactor();
  testDiscountFactor();
  testFundamentalValue();
  testEndValue();
  testFundamentalValueOfAnnuityInAdvance();
  testFundamentalValueOfAnnuityInArrear();
  testEndValueOfAnnuityInAdvance();
  testEndValueOfAnnuityInArrear();
  printf("stat::insurance is working.\n");
}

#endif

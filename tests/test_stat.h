/**
 * File              : test_stat.h
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 28.09.2019
 * Last Modified Date: 28.09.2019
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
/**
 * tests/test_stat.h
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
#ifndef TEST_STAT_H
#define TEST_STAT_H

#include "../lib/stat.h"
#include "../lib/array.h"
#include <tgmath.h>

double amount[10] = {1585.,1819.,1647.,1496.,921.,1278.,1810.,1987.,1612.,1413.};
double price[10] = {12.5,10.,9.95,11.5,12.,10.,8.,9.,9.5,12.5};

void test_abs_(){
  double a = -1.;
  double b =  1.;

  assert(abs_(a) == 1.);
  assert(abs_(b) == 1.);
  printf("stat::abs_ is working.\n");
}

void test_pow_(){
  double a =  2.;
  double b =  1.;
  double c = -3.;

  assert(pow_(a, 2)==  4.);
  assert(pow_(a, 0)==  1.);
  assert(pow_(b, 1)==  1.);
  assert(pow_(b, 2)==  1.);
  assert(pow_(c, 1)== -3.);
  assert(pow_(c, 2)==  9.);
  assert(pow_(c, 3)==-27.);
  
  printf("stat::pow_ is working.\n");
}

void test_mean_d(){
  double *a;
  a = allocArray(a, 2);
  a[0] =  5.;
  a[1] = 10.;
  assert(mean_d(a, 2) == 7.5);

  double *b;
  b = allocArray(b, 5);
  for(int i=0; i<5; i++){
    b[i] = i+1;
  }
  assert(mean_d(b, 5) == 3);
  printf("stat::mean_d is working.\n");
}

void test_round_(){
  double x = 0.123445;
  double y = -291.16778;

  assert(round_(x, 1) ==    0.1    ); 
  assert(round_(x, 2) ==    0.12   );
  assert(round_(x, 3) ==    0.123  );
  assert(round_(x, 4) ==    0.1234 );
  assert(round_(x, 5) ==    0.12345);

  assert(round_(y, 1) == -291.2    );
  assert(round_(y, 2) == -291.17   );
  assert(round_(y, 3) == -291.168  );
  assert(round_(y, 4) == -291.1678 );
  assert(round_(y, 5) == -291.16778);

  printf("stat::round_ is working.\n");
}

void test_cov_d(){
  double *x, *y;
  int size = 10;

  x = allocArray(x, size);
  y = allocArray(y, size);

  assignVals(x, amount, size);
  assignVals(y, price, size);
  assert(round_(cov_d(x, y, 10), 2)==-291.17);

  printf("stat::cov_d is working.\n");
}

void test_lm_d(){
  double *x, *y;
  int size = 10;

  x = allocArray(x, size);
  y = allocArray(y, size);

  assignVals(x, amount, size);
  assignVals(y, price, size);

  lmMod mod = lm_d(x, y, size);

  double meanA = mean_d(y, 10);
  double meanB = mean_d(mod.y_estimate, 10);

  assert(round_(mod.beta_0, 3) == 15.373);
  assert(round_(mod.beta_1, 3) == -0.003);
  assert(round_(meanA, 2) == round_(meanB, 2));
  assert(round_(mean_d(mod.residuals, 10), 10) == 0.); 

  printf("stat::lm_d is working.\n");
}

void testStat(){
  test_abs_();
  test_pow_();
  test_round_();
  test_mean_d();
  test_cov_d();
  test_lm_d();
  printf("stat is working.\n");
}

#endif

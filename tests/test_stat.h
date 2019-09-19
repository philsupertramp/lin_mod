#include "../lib/stat.h"
#include "../lib/array.h"
#include <tgmath.h>

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

  double absatz[10] = {1585.,1819.,1647.,1496.,921.,1278.,1810.,1987.,1612.,1413.};
  double preis[10] = {12.5,10.,9.95,11.5,12.,10.,8.,9.,9.5,12.5};

  assignVals(x, absatz, size);
  assignVals(y, preis, size);
  assert(round_(cov_d(x, y, 10), 2)==-291.17);

  printf("stat::cov_d is working.\n");
}

void testStat(){
  test_abs_();
  test_pow_();
  test_round_();
  test_mean_d();
  test_cov_d();

  printf("stat is working.\n");
}

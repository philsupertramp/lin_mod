/**
 * File              : dge.c
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 11.10.2019
 * Last Modified Date: 09.11.2019
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
#include <stdio.h>

#include "dge.h"
#include "../matrix.h"

void meshgrid(vector a, vector b, matrixD gridX, matrixD gridY) {
  for(int i=0; i<b.size; ++i){
    for(int j=0; j<a.size; ++j){
      gridX._e[getIndex(i, j, b.size, a.size)] = a._e[j];
      gridY._e[getIndex(i, j, b.size, a.size)] = b._e[i];
    }
  }
}

matrixD eval(double (*f)(double ti, double yi), matrixD t, matrixD y){
  matrixD result;
  if(t.cols != y.cols || t.rows != y.rows){
    matrixD ERROR;
    ERROR = initMatrix(ERROR, y.cols > t.cols ? y.cols : t.cols, y.rows > t.rows ? y.rows : t.rows);
    fprintf(stderr, "numerics::DGE::eval dimension missmatch t[%dx%d] != y[%dx%d]\n", t.rows, t.cols, y.rows, y.cols);
    return ERROR;
  }
  result = initMatrix(result, t.rows, t.cols);
  for(int i=0; i<t.cols; ++i){
    for(int j=0; j<t.rows; ++j){
      int index = getIndex(i, j, t.rows, t.cols);
      result._e[index] = f(t._e[index], y._e[index]);
    }
  }
  return result;
}
matrixD odeEulerExp(double (*fun)(double, double), vector tIntervall, vector y0, double h){
  double tStart = tIntervall._e[0];
  double tEnd = tIntervall._e[tIntervall.size - 1];
  
  int n = (int)((tEnd - tStart) / (double)h);
  vector t = initVec(t, n);

  matrixD result = initMatrix(result, n, y0.size + 1);
  for(int i=0;i<n;++i){
    result._e[getIndex(i, 0, result.rows, result.cols)] = i*h+tStart;
  }
  // assign row
  for(int i=0; i<y0.size;++i){
    result._e[getIndex(0, i + 1, result.rows, result.cols)] = y0._e[i];
  }
  for(int i=1; i<result.cols;++i){
    for(int j=1; j<result.rows;++j){
      double prev_y = result._e[getIndex(j - 1, i, result.rows, result.cols)];
      double prev_t = result._e[getIndex(j - 1, 0, result.rows, result.cols)];
      result._e[getIndex(j, i, result.rows, result.cols)] = prev_y + h * fun(prev_t, prev_y);
    }
  }

  return result;
}
matrixD odeEulerExt(double (*fun)(double, double), vector tIntervall, vector y0, double h){
  double tStart = tIntervall._e[0];
  double tEnd = tIntervall._e[tIntervall.size - 1];
  
  int n = (int)((tEnd - tStart) / (double)h);
  vector t = initVec(t, n);

  matrixD result = initMatrix(result, n, y0.size + 1);
  for(int i=0;i<n;++i){
    result._e[getIndex(i, 0, result.rows, result.cols)] = i*h+tStart;
  }
  // assign row
  for(int i=0; i<y0.size;++i){
    result._e[getIndex(0, i + 1, result.rows, result.cols)] = y0._e[i];
  }
  for(int i=1; i<result.cols;++i){
    for(int j=1; j<result.rows;++j){
      double prev_y = result._e[getIndex(j - 1, i, result.rows, result.cols)];
      double prev_t = result._e[getIndex(j - 1, 0, result.rows, result.cols)];
      double y_k = prev_y + h/2. * fun(prev_t, prev_y);
      result._e[getIndex(j, i, result.rows, result.cols)] = prev_y + h * fun(prev_t + h/2., y_k);
    }
  }

  return result;
}
matrixD odeRK34(double (*fun)(double, double), vector tIntervall, vector y0, double h){
  register int i, j;
 
  double tStart = tIntervall._e[0];
  double tEnd = tIntervall._e[tIntervall.size - 1];

  int n = (int)((tEnd - tStart) / (double)h);

  matrixD result = initMatrix(result, n, y0.size + 1);
  
  for(i=0;i<n;i++){
    result._e[getIndex(i, 0, result.rows, result.cols)] = i*h+tStart;
  }

  for(i=0; i<y0.size; ++i){
    result._e[getIndex(0, i + 1, result.rows, result.cols)] = y0._e[i];
  }
  // actual method
  for(i=1; i<result.rows; ++i){
    for(j=1; j<result.cols; ++j){
      double prev_y = result._e[getIndex(i - 1, j, result.rows, result.cols)];
      double prev_t = result._e[getIndex(i - 1, 0, result.rows, result.cols)];
      
      double k_1 = fun(prev_t, prev_y);
      double k_2 = fun(prev_t + h / 2., prev_y + h / 2. * k_1);
      double k_3 = fun(prev_t + h / 2., prev_y + h / 2. * k_2);
      double k_4 = fun(prev_t + h, prev_y + h * k_3);
      result._e[getIndex(i, j, result.rows, result.cols)] = prev_y + h / 6. * (k_1 + 2. * k_2 + 2. * k_3 + k_4);
    }
  }
  return result;
}


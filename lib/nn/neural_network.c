/**
 * File              : neural_network.c
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 28.09.2019
 * Last Modified Date: 03.10.2019
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 *
 * This file contains a version of code from <https://www.cs.bham.ac.uk/~jxb/NN/nn.html>
 *
 * lib/nn/neural_network.c
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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>

#include "neural_network.h"
#include "../matrix.h"

#define rando() ((double)rand()/((double)RAND_MAX+1))

#define eta     0.5
#define alpha   0.9
#define smallwt 0.5

double sigmoid(double t){
  // calculates the sigmoid function
  double result = 1. / (1. + exp(-t));
  return result;
}

double sigmoidDerivative(double sig){
  // simple derivative of sigmoid
  double result = sig * (1. - sig);
  return result;
}

void initWeight(matrix weight, matrix deltaWeight, int A, int B){
  // initializes random values for weights
  // deltaWeight does not need to be initialized with 0.
  // matrix::initMatrix takes care of that.

  weight = initMatrix(weight, A+1, B+1);
  deltaWeight = initMatrix(deltaWeight, A+1, B+1);

  for(int j=1;j<=A;j++){
    for(int i=0; i<=B;i++){
      int index = getIndex(i,j,A+1,B+1);
      weight._e[index] = 2. * (rando() - 0.5) * smallwt;
    }
  }
}

void initWeights(int numIn, int numHid, int numOut){
  // Generates a set of initialized weights and deltaWeights
  matrix weightIH, deltaWeightIH, weightHO, deltaWeightHO;
  initWeight(weightIH, deltaWeightIH, numHid, numIn);
  initWeight(weightHO, deltaWeightHO, numOut, numHid);
}

void train(
  matrix weightIH, matrix deltaWeightIH,
  matrix weightHO, matrix deltaWeightHO,
  matrix input, matrix target,
  matrix trainData,
  int numPatterns, int maxTrainIter
){
  int numHid, numIn, numOut, iterator0;
  for(int epoch=0; epoch<maxTrainIter; ++epoch){
    // randomize order of train data
    for(iterator0=0;iterator0<trainData.cols*trainData.rows;++iterator0){
      trainData._e[iterator0] = iterator0;
    }
    for(iterator0=0; iterator0<trainData.cols*trainData.rows;++iterator0){
      //TODO: finish    
    }

  }
  
}

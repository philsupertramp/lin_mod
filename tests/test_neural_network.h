/**
 * File              : test_neural_network.h
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 28.09.2019
 * Last Modified Date: 28.09.2019
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
/*
 *
 * tests/test_neural_network.h
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
#ifndef TEST_NEURAL_NETWORK
#define TEST_NEURAL_NETWORK

#include "../lib/nn/neural_network.h"
#define TEST void

TEST testSigmoid(){
  double result = sigmoid(0);
  assert(result==0.5);
  result = sigmoid(1);
  assert(round_(result, 2) == 0.73);
  printf("neural_network::sigmoid is working.\n");
}

TEST testSigmoidDerivative(){
  double result = sigmoidDerivative(0.5);
  assert(round_(result, 2)==0.25);
  printf("neural_network::sigmoidDerivative is working.\n");
}

TEST testNeuralNetwork(){
  testSigmoid();
  testSigmoidDerivative();
  printf("neural_network is working.\n");
}
#endif

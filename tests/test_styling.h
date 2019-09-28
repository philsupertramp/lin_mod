/**
 * File              : test_styling.h
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 28.09.2019
 * Last Modified Date: 28.09.2019
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
/**
 * tests/test_styling.h
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
#ifndef TEST_STYLING_H
#define TEST_STYLING_H
#include <stdio.h>

#include "../lib/styling.h"

void cprintTest();
void testStyling();

void cprintColors(int bold){
  cprint(RED, bold, stdout);
  printf("TEST\n");
  cprint(RESET, 0, stdout);
  cprint(GREEN, bold, stdout);
  printf("TEST\n");
  cprint(RESET, 0, stdout);
  cprint(BLUE, bold, stdout);
  printf("TEST\n");
  cprint(RESET, 0, stdout);
  cprint(YELLOW, bold, stdout);
  printf("TEST\n");
  cprint(RESET, 0, stdout);
  cprint(MAGENTA, bold, stdout);
  printf("TEST\n");
  cprint(RESET, 0, stdout);
  cprint(CYAN, bold, stdout);
  printf("TEST\n");
  cprint(RESET, 0, stdout);

}

void cprintTest(){
  cprintColors(0);
  cprintColors(1);
  printf("styling::pprint is working.\n");
}

void testStyling(){
  cprintTest();
  
  printf("styling is working.\n");
}

#endif

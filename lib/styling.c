/**
 * File              : styling.c
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 28.09.2019
 * Last Modified Date: 28.09.2019
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
/**
 * lib/styling.c
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
#include "styling.h"

// font style
const char *NORMAL = "0;";
const char *BOLD = "1;";
// colors
const char *RED = "31";
const char *GREEN = "32";
const char *YELLOW = "33";
const char *BLUE = "34";
const char *MAGENTA = "35";
const char *CYAN = "36";
// reset
const char *RESET = "0";

void cprint(const char *color, bool bold, FILE* streamOut){
  bool reset = color==RESET;
  if(color==RESET){
    fprintf(streamOut, "\033[0m");
    return;
  }
  if(bold){
    fprintf(streamOut, "\033[1;");
  }
  else{
    fprintf(streamOut, "\033[0;");
  }
  fprintf(streamOut, color);
  fprintf(streamOut, "m");
}




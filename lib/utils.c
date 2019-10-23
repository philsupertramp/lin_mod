/**
 * File              : utils.c
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 22.10.2019
 * Last Modified Date: 22.10.2019
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
#include "utils.h"

void remove_space(char *s){  
  const char *d = s;
  do {
    while (*d == ' ' || *d == '\n'){
      ++d;
    }
  } while (*s++ == *d++);
}



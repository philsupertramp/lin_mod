#ifndef STYLING_H
#define STYLING_H
/*
 * Text based formatting
 */
#include <stdbool.h>
#include <stdio.h>

// font style
const char *NORMAL;
const char *BOLD;
// colors
const char *RED;
const char *GREEN;
const char *YELLOW;
const char *BLUE;
const char *MAGENTA;
const char *CYAN;
// reset
const char *RESET;


void cprint(const char *, bool, FILE*);

#endif

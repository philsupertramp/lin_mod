#ifndef STYLING_H
#define STYLING_H
/*
 * Text based formatting
 */
#include <stdbool.h>
#include <stdio.h>

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


void cprint(const char *, bool, FILE*);
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

#endif

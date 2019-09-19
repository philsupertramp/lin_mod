/*
 * Text based formatting
 */
#include <stdbool.h>
#include <stdio.h>

// font style
char *NORMAL = "0;";
char *BOLD = "1;";
// colors
char *RED = "31";
char *GREEN = "32";
char *YELLOW = "33";
char *BLUE = "34";
char *MAGENTA = "35";
char *CYAN = "36";
// reset
char *RESET = "0";


void cprint(char *, bool, FILE*);
void cprint(char *color, bool bold, FILE* streamOut){
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

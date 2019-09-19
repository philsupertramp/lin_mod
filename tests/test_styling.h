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

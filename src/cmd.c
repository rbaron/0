#include <stdio.h>
#include <string.h>

#include "stack.h"
#include "cmd.h"
#include "op.h"
#include "config.h"

int cmd_exec(stack_t *stack, char *string) {
  char *c;

  c = string;

  //Makes sure command has the desired format
  if(strlen(c) > 2 && *c == CONFIG_DECIMAL_POINT && *(c+1) == CONFIG_DECIMAL_POINT) {
    c = c + 2;
  }
  else {
    fprintf(stderr, "Unrecognized command.\n");
    return -1;
  }

  //CMD_POP
  if(!strcmp(c, CMD_POP)) {
    if(stack->size > 0) {
      stack_pop(stack);
      return 0;
    }
    else {
      fprintf(stderr, "Stack is already empty!\n");
      return -1;
    }
  }

  //CMD_CLEAR
  else if(!strcmp(c, CMD_CLEAR)) {
    stack->size = 0; 
    return 0;
  }

  //CMD_HELP
  else if(!strcmp(c, CMD_HELP)) {
    cmd_print_help();
    return 0;
  }

  else {
    fprintf(stderr, "Unrecognized command.\n");
    return -1;
  }
}


int cmd_print_help() {
  printf("\nHelp:\n=====\n\n");

  printf("Operations:\n");
  printf("%s\t y + x  \n", OP_ADD);
  printf("%s\t y - x  \n", OP_MINUS);
  printf("%s\t y * x  \n", OP_MULT);
  printf("%s\t y / x  \n", OP_DIV);
  printf("%s\t y ^ x  \n", OP_EXP);
  printf("%s\t y ^ 1/x\n", OP_ROOT);
  
  printf("\nCommands:\n");
  printf("%c%c%s\t pop the stack  \n", CONFIG_DECIMAL_POINT, CONFIG_DECIMAL_POINT, CMD_POP);
  printf("%c%c%s\t clear the stack  \n", CONFIG_DECIMAL_POINT, CONFIG_DECIMAL_POINT, CMD_CLEAR);
  printf("%c%c%s\t print this help  \n", CONFIG_DECIMAL_POINT, CONFIG_DECIMAL_POINT, CMD_HELP);

  printf("\n");

  return 0;
}


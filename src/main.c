#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "ui.h"
#include "validate.h"

int print_usage() {
  printf("Usage:\nYOU tell me!");
  return 0;
}

int main() {
  char input[32];

  stack_t *stack = malloc(sizeof(stack_t));
  stack_init(stack);

  while(1) {
    if(fgets(input, sizeof(input), stdin)) {
      
      //What was the user's input? 
      switch(validate_input(input)) {
        case VALIDATE_NUMBER:
          //op_exec(stack, buff);
          break;

        case VALIDATE_OPERATION:
          //op_exec(stack, buff);
          break;

        case VALIDATE_COMMAND:
          //cmd_exec(buff);
          break;

        default:
          print_usage();
          break;
      }

      ui_refresh(stack);
    }
  }

  return 0;
}

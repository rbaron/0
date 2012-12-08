#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "ui.h"
#include "validate.h"
#include "config.h"

int print_help() {
  printf("Usage:\nYOU tell me!\n");
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
          stack_push(stack, strtod(input, NULL));
          printf("Converted: %f\n",strtod(input, NULL)); 
          break;

        case VALIDATE_OP:
          //op_exec(stack, buff);
          break;

        case VALIDATE_CMD:
          //cmd_exec(buff);
          break;

        default:
          printf("Unrecognized input. Type %c%c0 for help.\n", CONFIG_DECIMAL_POINT, CONFIG_DECIMAL_POINT);
          break;
      }

      ui_refresh(stack);
    }
  }

  return 0;
}

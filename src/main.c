#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "ui.h"
#include "validate.h"
#include "op.h"
#include "cmd.h"
#include "config.h"

int main() {
  char input[CONFIG_MAX_INPUT_LENGTH];
  stack_t *stack = malloc(sizeof(stack_t));

  stack_init(stack);

  while(1) {
    ui_refresh(stack);

    if(fgets(input, sizeof(input), stdin)) {
      
      //What was the user's input? 
      switch(validate_input(input)) {
        case VALIDATE_NUMBER:
          stack_push(stack, strtod(input, NULL));
          break;

        case VALIDATE_OP:
          op_exec(stack, input);
          break;

        case VALIDATE_CMD:
          cmd_exec(stack, input);
          break;

        default:
          printf("Unrecognized input. Type %c%c%s for help.\n", CONFIG_DECIMAL_POINT, CONFIG_DECIMAL_POINT, CMD_HELP);
          break;
      }
    }
  }

  return 0;
}

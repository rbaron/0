#include <stdio.h>
#include <string.h>
#include <math.h>

#include "op.h"
#include "stack.h"


int op_exec(stack_t *stack, char *string) {
  double x, y;

  if(stack->size >= 2) {
    x = stack_pop(stack);
    y = stack_pop(stack);

    if(!strcmp(string, OP_ADD)) stack_push(stack, y+x);
    else if(!strcmp(string, OP_MINUS)) stack_push(stack, y-x);
    else if(!strcmp(string, OP_DIV)) stack_push(stack, y/x);
    else if(!strcmp(string, OP_MULT)) stack_push(stack, y*x);
    else if(!strcmp(string, OP_EXP)) stack_push(stack, pow(y, x));
    else if(!strcmp(string, OP_ROOT)) stack_push(stack, pow(y,1/x));
    else {
      fprintf(stderr, "Unrecognized operation.\n");
      stack_push(stack, y);
      stack_push(stack, x);
      return -1;
    }
    return 0;
  }
  else {
    fprintf(stderr, "Not enough operands on the stack!\n");
    return -1;
  }
}

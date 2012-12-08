#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "ui.h"


int ui_refresh(stack_t *stack) {
  stack_t *copy = malloc(sizeof(stack_t));
  stack_copy_and_invert(stack, copy);

  printf("Stack:\n");
  while(copy->size > 0) {
    printf("%f\n", stack_pop(copy));
  } 

  free(copy);
 
  return 0;
}

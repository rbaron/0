#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "ui.h"
#include "config.h"


int ui_refresh(stack_t *stack) {
  stack_t *copy = malloc(sizeof(stack_t));
  
  //Dynamic format string, based on config.h:CONFIG_SIGNIFICANT_DIGITS
  char format[10];
  snprintf(format, sizeof(format), "%%.%dg\n", CONFIG_SIGNIFICANT_DIGITS);

  stack_copy_and_invert(stack, copy);

  printf("\nStack:\n======\n");

  if(stack->size == 0) printf("(empty)\n");

  while(copy->size > 0) {
    if(copy->size > 2) printf("   ");
    else if(copy->size == 2) printf("Y: ");
    else if(copy->size == 1) printf("X: ");
    printf(format, stack_pop(copy));
  } 

  printf("\n");

  free(copy);
 
  return 0;
}

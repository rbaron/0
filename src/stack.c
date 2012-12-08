#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

int stack_init(stack_t *s) {
  s->size = 0;
  return 0;
}

double stack_pop(stack_t *s) {
  if(s->size <= 0) {
    fprintf(stderr, "Cannot pop stack. It's already empty!");
    return -1.0;
  }
  else return s->content[--s->size];
}

int stack_push(stack_t *s, double element) {
  if(s->size >= STACK_MAX_SIZE) {
    fprintf(stderr, "Cannot push element onto the stack. It's full!");
    return -1;
  }
  else {
    s->content[s->size++] = element;
    return 0;
  }
}

int stack_copy(stack_t *src, stack_t *dst) {
  memcpy(dst, src, sizeof(stack_t));
  return 0;
}

int stack_copy_and_invert(stack_t *src, stack_t *dst) {
  stack_t *copy = malloc(sizeof(stack_t));
  stack_copy(src, copy);

  dst->size = 0;
  while(dst->size < src->size) {
    stack_push(dst, stack_pop(copy));
  }
  return 0;
}

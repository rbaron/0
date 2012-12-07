#ifndef _stack_h_
#define _stack_h_

#define STACK_MAX_SIZE 100

typedef struct {
  float content[STACK_MAX_SIZE];
  int size;
} stack_t;

int stack_init(stack_t *s);
float stack_pop(stack_t *s);
int stack_push(stack_t *s, float element);
int stack_copy(stack_t *src, stack_t *dst);
int stack_copy_and_invert(stack_t *src, stack_t *dst);

#endif

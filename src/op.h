#ifndef _op_h_
#define _op_h_

#include "stack.h"

#define OP_ADD "+"
#define OP_MINUS "-"
#define OP_MULT "*"
#define OP_DIV "/"
#define OP_ROOT "//"
#define OP_EXP "**"

int op_exec(stack_t *stack, char *string);

#endif

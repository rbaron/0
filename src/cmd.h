#ifndef _cmd_h_
#define _cmd_h_

#include "stack.h"
#include "config.h"

#define CMD_POP "0"
#define CMD_CLEAR "1"
#define CMD_HELP "2"

int cmd_exec(stack_t *stack, char *string);

int cmd_print_help();

#endif

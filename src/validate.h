#ifndef _validate_h_
#define _validate_h_

#define VALIDATE_NUMBER 0x1
#define VALIDATE_OP 0x2
#define VALIDATE_CMD 0x3

int validate_input(char *string);

int validate_number(char *string);
int validate_cmd(char *string);
int validate_op(char *string);

#endif

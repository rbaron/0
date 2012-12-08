#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "validate.h"
#include "config.h"
#include "cmd.h"

/*
  Decides if char* string is a number, an operation or a command
*/
int validate_input(char *string) {
  
  //Is it a number?
  if(validate_number(string)) {
    printf("Input is a number!\n");
    return VALIDATE_NUMBER;
  }
  //Is it a command?
  if(validate_cmd(string)) {
    printf("Input is a command!\n");
    return VALIDATE_CMD;
  }

  return 0;
}

/*
  Return 1 if string is a number
  or 0 if it's not

  If string IS a number, this function also replaces every CONFIG_DECIMAL_POINT with '.'
*/
int validate_number(char *string) {
  char *c = NULL;
  char *dec_point = NULL;

  char copy[strlen(string)+1];

  strcpy(copy, string);


  c = copy;
  while(*c != '\0') {

    //Allow minus sign on first position, only if next digit is valid (to be analysed)
    if(*c == '-' && (c - copy) == 0 && *(c+1) != '\n' && *(c+1) != '\0') {
    }
    
    //Valid ASCII [0..9]
    else if((unsigned char) *c >= 0x30 && (unsigned char) *c <= 0x39) {
    }

    //If a CONFIG_DECIMAL_POINT is found, make sure it's the only one
    else if(*c == CONFIG_DECIMAL_POINT && dec_point == NULL) {
      *c = '.';
      dec_point = c;
    }

    //If a \n is found, assume number ends there
    else if(*c == '\n') {
      *c = '\0';
      break;
    }

    else {
      //fprintf(stderr, "String is not a number. Invalid character
      // at location %d (char = '%c')\n", (int)(c-string+1), *c);
      return 0;
    }

    c++;

  }

  //Try to convert to double
  /* 
    From strtod() man:

    Since 0 can legitimately be returned on both success and failure, the calling
       program should set errno to 0 before the call, and then determine if an error
       occurred by checking whether errno has a nonzero value after the call.

  */
  errno = 0;
  if(!errno) {
    //String is a number. Write back our modifications on the original string
    strcpy(string, copy);
    return 1;
  }
  else {
    fprintf(stderr, "Error: input was accepted as a number but conversion failed..\n");
  }

  return 0;
}

/*
  Return 1 if string is a command
  or 0 if it's not
  
  Commands are started by two CONFIG_DECIMAL_POINTs.
  For availables commands, see cmd.h
*/
int validate_cmd(char *string) {
  char *c = NULL;

  //Remove eventual '\n' from string
  if((c = strchr(string, '\n')) != NULL) *c = '\0';

  c = string;

  if(strlen(c) > 2 && *c == CONFIG_DECIMAL_POINT && *(c+1) == CONFIG_DECIMAL_POINT) {
    c = c + 2;

    if(!strcmp(c, CMD_POP)) return 1;
  }

  return 0;
}


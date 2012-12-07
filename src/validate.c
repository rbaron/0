#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "validate.h"
#include "config.h"

/*
  Return 1 if string is a number
  or 0 if it's not
*/
int validate_number(char *string) {
  char *c;
  float r;

  //Is user using the right decimal point?
  //if(!strcmp(",", j

  //Check for decimal point
  c = strchr(string, CONFIG_DECIMAL_POINT);

  if(c != NULL) {
    //Replace CONFIG_DECIMAL_POINT with standard "."
    *c = '.';

    //If we find another decimal point, return error
    if(strchr(string, CONFIG_DECIMAL_POINT) != NULL) {
      fprintf(stderr, "Error: more than one decimal point found.\n");
      return 0;
    }

    //If there's nothing after the decimal point
    /*
    if(strlen(string) <= (int) (c-string)) {
      fprintf(stderr, "Error: more than one decimal point found.\n");
      return 0;
    }
    */
  }

  //Try to convert to float
  if((r = strtof(string, NULL))) {
    printf("Tudo bem na conversao: r = %f", r);
    return 1;
  }
  
  return 0;
}

int validate_input(char *string) {
  
  //Is it a number?
  if(validate_number(string)) {
    printf("Input is a number!\n");
    return VALIDATE_NUMBER;
  }

  return 0;
}

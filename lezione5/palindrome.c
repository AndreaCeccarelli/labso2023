#include <stdio.h>

#include "reverse.h"

#include "palindrome.h"

int palindrome ( char *str ) {

  char reversedStr [100];

  reverse (str, reversedStr);

  return (strcmp (str, reversedStr) == 0);
}




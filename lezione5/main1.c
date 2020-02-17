#include <stdio.h>

#include "reverse.h"

int main (void) {

  char str [100];

  reverse ("cat", str); //Inverte la stringa "cat"

  printf ("reverse (\"cat\") = %s\n", str);

  reverse ("noon", str); //Inverte la stringa "noon"

  printf ("reverse (\"noon\") = %s\n", str);

  return 0;

}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
int main() {
  printf("test"); //--> provare con o senza \n; provare con una print nel figlio.
  int son = fork();
  if (son < 0) {
    exit(EXIT_FAILURE);
  } else if (son != 0) {
    wait(&son);
  } else {
    exit(EXIT_SUCCESS);
  }
  exit(EXIT_SUCCESS);
}


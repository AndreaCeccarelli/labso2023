#include <stdio.h>
#include <unistd.h>
#define READ 0
#define WRITE 1
int main (int argc, char *argv []) {
  int fd [2];
  pipe (fd); /* Create an unamed pipe */
  if (fork () != 0) { /* Parent, writer */
    close (fd[READ]); /* Close unused end */
    dup2 (fd[WRITE], 1); /* Duplicate used end to stdout */
    close (fd[WRITE]); /* Close original used end */
    /* Execute writer program */
    execlp (argv[1], argv[1], NULL); 
    perror ("connect"); /* Should never execute */
  } else { /* Child, reader */
    close (fd[WRITE]); /* Close unused end */
    /* Duplicate used end to stdin */
    dup2 (fd[READ], 0); 
    close (fd[READ]); /* Close original used end */
    /* Execute reader program */
    execlp (argv[2], argv[2], NULL); 
    perror ("connect"); /* Should never execute */
  }
}


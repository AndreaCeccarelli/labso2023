#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main (void) {
  int pid;
  int status=0;
  printf ("PID %d and PPID %d.\n", getpid (), getppid ());
  pid = fork (); /* FORK */
  if (pid != 0) { /* pid is non-zero, parent */
    pid = fork (); /* FORK */
    if (pid != 0) { /* pid is non-zero, parent */
      sleep(15); 
      wait(&status);
      sleep(15);
    }
    else{
       printf ("PID %d and PPID %d.\n", getpid (), getppid ());
    }
  }
  else { /* pid is zero, so I must be the child */
    printf ("PID %d and PPID %d.\n", getpid (), getppid ());
  }

  return 0;
}

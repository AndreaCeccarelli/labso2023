#include <stdio.h>
int main (void) {
  int pid;
  printf ("PID %d and PPID %d.\n", getpid (), getppid ());
  pid = fork (); /* FORK */
  if (pid != 0) { /* pid is non-zero, parent */
    printf ("PID %d and PPID %d.\n", getpid (), getppid ());
    printf ("My child’s PID is %d.\n", pid);
    sleep(5); //verificare senza sleep: padre potrebbe terminare prima di figlio
  }
  else { /* pid is zero, so I must be the child */
    printf ("PID %d and PPID %d.\n", getpid (), getppid ());
  }
  printf ("PID %d terminates.\n", getpid () ); /* both print this */
	exit(0);
  return 0;
}


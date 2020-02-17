#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
int delay;
void childHandler (int);
int main (int argc, char *argv[]) {
 int pid;
/*Install death-of-child handler */
 signal (SIGCHLD, childHandler); 
 pid = fork (); /* Duplicate */
 if (pid == 0) { /* Child */
  execvp (argv[2], &argv[2]); /* Execute command */
  perror ("limit"); /* Should never execute */
 } else { /* Parent */
	/* Read delay from command line */
  sscanf (argv[1], "%d", &delay);
  sleep (delay); /*Sleep */
  printf ("Child %d exceeded limit and is killed\n", pid);
  kill (pid, SIGINT); /* Kill the child */
 }
 return 0;
}

void childHandler (int sig) { /* Executed if the child dies */
  int childPid, childStatus; /* before the parent */
  /* Accept child termination code */
  childPid = wait (&childStatus); 
  printf ("Child %d terminated within %d seconds\n", 
          childPid, delay);
  exit (0);
}


#include <signal.h>
#include <stdio.h>
#include <termio.h>
#include <fcntl.h>
#include <stdlib.h>
void sigHandler (int sig) {
  printf ("%d Attempted inappropriate read from control terminal\n", sig);
  exit (1);
}

int main (void) {
  int status; char str [100];
  if (fork () == 0) { /* Child */
     signal (SIGTTIN, sigHandler); /* Install handler */
     /* Place myself in a new process group */
     setpgid (0, getpid ());
printf ("Enter a string: ");
     scanf ("%s", str); /* Try to read from control terminal */
     printf ("You entered %s\n", str); /* not executed*/
  } else { /* Parent */
     wait (&status); /* Wait for child to terminate */
  }
}


#include <signal.h>
#include <stdio.h>
void sigHandler (int sig) {
  printf("Process %d got a %d signal \n", getpid (), sig);
}

int main (void) {
  signal (SIGINT, sigHandler); /* Handle Control-C */
  if (fork () == 0)
    printf ("Child PID %d PGRP %d waits\n", getpid (),
      getpgid (0));
  else
     printf ("Parent PID %d PGRP %d waits\n", getpid (),
       getpgid (0));
  pause (); /* Wait for a signal */
}


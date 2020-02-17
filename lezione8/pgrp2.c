#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void sigHandler (int sig) {
  printf ("Process %d got a SIGINT\n", getpid ());
  exit (1);
}

int main (void) {
  int i;
  signal (SIGINT, sigHandler); /* signal handler */
  if (fork () == 0)
     /* child in its own process group */
     setpgid (0, getpid ()); 
printf ("Process PID %d PGRP %d waits\n",
    getpid (), getpgid (0));
  
  for (i = 1; i <= 3; i++) { 
  /* Loop three times */
     printf ("Process %d is alive\n",getpid ());
     sleep(2);
  }
  return 0;
}


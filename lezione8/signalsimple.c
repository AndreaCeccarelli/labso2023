#include <stdio.h>
#include <signal.h>
int main (void) {
  void (*oldHandler) (int); /* To hold old handler value */
  printf ("I can be Control-C’ed\n");
  sleep (3);
  oldHandler = signal (SIGINT, SIG_IGN); /*Ignore Control-C*/
  printf ("I’m protected from Control-C now\n");
  sleep (3);
  signal (SIGINT, oldHandler); /* Restore old handler */
  printf ("I can be Control-C’ed again\n");
  sleep (3);
  printf ("Bye!\n");
  return 0;
}


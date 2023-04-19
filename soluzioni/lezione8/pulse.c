#include <signal.h>
#include <stdio.h>
int main (void) {
 int pid1; int pid2;
 pid1 = fork ();
 if (pid1 == 0) { /* First child */
   while (1) { /* Infinite loop */
     printf ("pid1 is alive\n");
     sleep (1);
   }
 }
 pid2 = fork ();
 if (pid2 == 0) { /* Second child */
   while (1) { /* Infinite loop */
     printf ("pid2 is alive\n");
     sleep (1);
   }
 }
  sleep (3);
  kill (pid1, SIGSTOP); /* Suspend first child */
  sleep (3);
  kill (pid1, SIGCONT); /* Resume first child */
  sleep (3);
  kill (pid1, SIGINT); /* Kill first child */
  kill (pid2, SIGINT); /* Kill second child */
  return 0;
}

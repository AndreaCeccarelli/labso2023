#include <signal.h>
#include <stdio.h>
int main (void) {
  int pid1; int pid2;
  pid1 = fork ();
  if (pid1 == 0) { /* First child */
    [fare un loop infinito con i) stampa nome PID; ii) sleep 1 secondo]
  }
  pid2 = fork ();
  if (pid2 == 0) { /* Second child */
    [fare un loop infinito con i) stampa nome PID; ii) sleep 1 secondo]
  }
  sleep (3);
  [sospendere pid1 con segnale SIGSTOP]
  sleep (3);
  [riavviare pid1 con segnale SIGCONT]
  sleep (3);
  [uccidere pid1 con segnale SIGSINT]
  [uccidere pid2 con segnale SIGSINT]
  return 0;
}


  

#include <sys/types.h>

#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

int main(int argc, char **argcv) {
  int pid;
  int somma=0;
  //prendi input (in argv[1])
  input= ?

  
  pid = fork();
  if (pid == 0) { /* codice eseguito dal figlio */

    //effettua somma input
  	?  
    //stampa ProcessoFiglioPid:numPidvalorefinale=...
	? 

  } else if (pid > 0) { /* codice eseguito dal padre */
    //effettua somma input +10
	?
    //stampa ProcessoPadrePid:numPidvalorefinale=...
	? 

  } else { /* codice eseguito dal padre in caso di errore */
    printf("Si e' verificato un errore nella chiamata a fork.\n");
  }
  return;
}



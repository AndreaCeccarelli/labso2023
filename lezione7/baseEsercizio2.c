#include <sys/types.h>

#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

int main(int argc, char **argcv) {
  int pid;
  int somma=0;
  int input=atoi(argcv[1]);//????

  //prendi input (in argv[1])
  
  pid = fork();
  if (pid == 0) { /* codice eseguito dal figlio */

    //effettua somma input +5
    somma=input+5;
    printf("somma : %d \n",somma);
   

  } else if (pid > 0) { /* codice eseguito dal padre */
    //effettua somma input +10
    somma=input+10;
    printf("somma : %d\n", somma);

  } else { /* codice eseguito dal padre in caso di errore */
    printf("Si e' verificato un errore nella chiamata a fork.\n");
  }
  return;
}



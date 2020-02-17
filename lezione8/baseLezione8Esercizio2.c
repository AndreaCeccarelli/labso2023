#include <stdio.h>
#include <signal.h>
#define max 10

void gestore_att(int sig);
void figlio(char *com);

main(int argc , char *argv[]) {
      int ppid, pid[max], pf;
      int status, i;
      if (argc==1)
      {
	//sintassi sbagliata
	[stampare a video "sintassi sbagliata"]
      }
      ppid=getpid();

      for(i=0; i< argc-1; i++)
      {
            pid[i]=fork();
            if (pid[i]==0)
            {
                  printf("sono il figlio\n");
                  figlio(argv[i+1]);
                  exit(0);
            }
            else{
                  printf("%d: creato figlio %d\n", ppid, pid[i]);
            }
      }
      sleep(2); /* solo per ritardare..*/
      if ((ppid%2)==0)
      /*attivazione dei pari e uccisione dei dispari: SIGUSR1 */

            /*attivazione dei pari e uccisione dei dispari: SIGUSR1 */
            [è una kill con segnale SIGUSR1 per tutti i processi figlio creati]
      else
            /*attivazione dei dispari e uccisione dei pari: SIGUSR2 */
            [è una kill con segnale SIGUSR2 per tutti i processi figlio creati]


      /*raccogliere lo stato di terminazione di tutti i figli*/   
	[e' un for sul numero di processi creati;
	si effettua un numero di wait pari al numero di processi creati]

      exit(0);
}


void figlio(char *com){
      int miopid;
      miopid=getpid();
      if ((miopid%2)==0)
            signal(SIGUSR1, gestore_att);
      else
            signal(SIGUSR2, gestore_att);
      pause();
      execlp(com, com,(char *)0);
}

void gestore_att(int sig){
      printf("%d: sono stato attivato!\n",
      getpid());
      return;
}




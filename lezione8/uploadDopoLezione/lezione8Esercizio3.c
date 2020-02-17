#include <stdio.h> /* serve per la perror */
#include <stdlib.h> /* serve per la exit */
#include <errno.h> /* serve per errno */
#include <signal.h>
#define IFERROR(s,m) if((s)==-1) {perror(m); exit(errno);}

void gestore_SIGSEGV(int);
struct sigaction azione;

int main(int argc, char * argv[]){
               char stringa[10] ;
		IFERROR(sigaction(SIGSEGV,NULL,&azione),"eseguendo la sigaction");
               azione.sa_handler=gestore_SIGSEGV;
		IFERROR(sigaction(SIGSEGV,&azione,NULL),"eseguendo la sigaction");
               /* installo gestore per SIGSEGV */
               stringa[100000]=1; /* scrivo in area non assegnata */
               return(0);
}

void gestore_SIGSEGV(int sig) {
               printf("ricevuto segnale numero %d\n",sig);
               exit(-1);
}



#include <stdio.h>
#include <signal.h>
#define max 10
void gestore_att(int sig);
void figlio(char *com);
main(int argc , char *argv[])
{
	int ppid, pid[max], pf;
	int status, i;
	if (argc==1)
	{ 
		exit(1);
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
		for(i=0; i<argc-1; i++)
			kill(pid[i], SIGUSR1);
	else
		for(i=0; i<argc-1; i++)
			kill(pid[i], SIGUSR2);
	for (i=0; i<argc-1; i++){
		pf=wait(&status);
		if ((char)status==0)
			printf("terminato%d con stato%d\n", pf, status>>8);
		else
			printf("terminato %d involontariamente (segnale %d)\n", pf, (char)status);
	}
	exit(0);
}

void figlio(char *com)
{ 
	int miopid;
	miopid=getpid();
	if ((miopid%2)==0)
		signal(SIGUSR1, gestore_att);
	else
		signal(SIGUSR2, gestore_att);
	pause();
	execlp(com, com,(char *)0);
}
void gestore_att(int sig)
{
	printf("%d: sono stato attivato!\n",
	getpid());
	return;
}


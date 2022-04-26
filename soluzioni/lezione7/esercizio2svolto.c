#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h> /* necessario per atoi() */
#include <stdio.h>

int main(int argc,char **argcv) {
	int valore = 0;
        if ( 1 < argc )
        	valore = atoi( argcv[ 1 ] );
		printf("Unico processo con PID %d.\n",getpid());
		int pid = fork();
		if (pid == 0) { /* codice eseguito dal figlio */
			printf( "figlio [pid: %d]> valore iniziale= %d\n", getpid(), valore );
			valore += 15;
			printf( "figlio [pid: %d]> valore finale= %d\n", getpid(), valore );
		}
	else if (pid > 0) {
	/* codice eseguito dal padre */
		printf("padre [pid: %d]> generato un figlio; il suo pid e' %d\n",getpid(), pid);
		printf( "padre [pid: %d]> valore = %d\n", getpid(), valore );
		valore += 10;
		printf( "padre [pid: %d]> valore finale= %d\n", getpid(), valore );
	} else {
	/* codice eseguito dal padre in caso di errore */
		printf("padre [pid: %d]> problemi durante creazione del              figlio.\n",getpid());
		exit(1);
	}
	exit(0);
}

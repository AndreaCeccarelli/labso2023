#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]){
	int fd, esito, pid;
	char comando[20];
	unlink("esecutore_3");
	printf("unlink terminata con errno: %d\n",errno);
	errno=0;
	while(1) {
		esito = mkfifo("esecutore_3", 0777);
		printf("mkfifo terminata con errno %d\n",errno);
		if ( esito == -1 ) {
			printf("Errore nella creazione della FIFO dell'esecutore 3 del cluster\n");
			exit(1);
		}
		fd = open("esecutore_3",O_RDONLY);
		if ((esito = read(fd, &comando, sizeof(comando))) != 0) {
			unlink("esecutore_3");
			printf("Richiesta di esecuzione di: %s\n", comando);
			sleep(10);
			pid = fork(); //creo un figlio che esegue la execlp
			if (pid == 0)
				execlp(comando, comando, (char *)0);
 		}
 	}
}

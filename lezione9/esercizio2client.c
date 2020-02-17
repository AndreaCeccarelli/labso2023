#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int fd, esito;
	char r[20];
	fd=-1;
	printf("Inserisci il comando da eseguire: ");
	scanf("%s", r);
	fd = open("esecutore_1", O_WRONLY);
	printf("open su esecutore 1 terminata con codice di errore: %d e fd: %d\n",errno, fd);
	if ( fd == -1 ) {
		fd=0;
		fd = open("esecutore_2", O_WRONLY);
		printf("open su esecutore 2 terminata con codice di errore: %d e fd: %d\n",errno, fd);
	} if ( fd == -1 ){
		fd=0;
		 fd = open("esecutore_3", O_WRONLY);
		printf("open su esecutore 3 terminata con codice di errore: %d e fd: %d\n",errno, fd);
	} if ( fd == -1 ){
		printf("\nServizio non disponibile \n");
		exit(1);
	}

	esito = write(fd, &r, sizeof(r));
	esito = close(fd);
	exit(0);
}


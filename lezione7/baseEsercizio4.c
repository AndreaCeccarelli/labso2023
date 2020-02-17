#include <stdio.h> /* perror */
#include <errno.h> /* perror */
#include <unistd.h> /* write, lseek, close, exit */
#include <sys/types.h> /*open, lseek */
#include <sys/stat.h> /*open */
#include <fcntl.h> /*open*/
#define READLENGTH 10
#define WRITELENGTH 10

main(int argc, char **argv) {
 int infile, status, oufile, pid, nread, pid_processo;
 char buf[40]; char id[10];

//verificare che parametri di input sono esattamente tre, altrimenti stampare errore a video
if(argc !=3){
	printf("errore\n\n");
	exit(0);
}
// Apertura file output
[aprire l'output file, e' in argv[2] ]

 open(argv[2], ...

 /*Esecuzione fork*/
 if ((pid = fork()) == -1) {
  perror("fork");
  exit(1);
 } else if (pid == 0) {  /*Processo figlio*/
 // Apertura file inputFile, e' in argv[1]
  [aprire file inputfile]

 //legge i primi 10 caratteri, con una read
  [leggere 10 caratteri]

  /*scrive i primi 10 caratteri*/
  if ( (write(oufile, buf, WRITELENGTH )) <= 0) {
   close(oufile);
   exit(1);
  }
  sprintf(id, "(PID:%d) PF ", getpid());
  if ( (write(oufile, id, strlen(id))) <= 0) {
   close(oufile);
   exit(1);
  } /* chiude il proprio file descriptor */
  close(infile);
  exit(0);
 }
 else { /*Processo Padre*/

  //attende con una wait che il figlio finisca di scrivere
  [inserire una wait]

  printf("Inizio processo padre\n");

  //prende il pid del padre
  [prendere PID padre]

  //scrivere su file
  [scrive il pid del padre su file]

 }
 close(oufile);
 printf("Fine processo padre\n");
 exit(0);
}


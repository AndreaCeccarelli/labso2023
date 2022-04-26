#include <stdio.h> /* perror */
#include <errno.h> /* perror */
#include <unistd.h> /* write, lseek, close, exit */
#include <sys/types.h> /*open, lseek */
#include <sys/stat.h> /*open */
#include <fcntl.h> /*open*/
#define READLENGTH 10
#define WRITELENGTH 10

main(int argc, char **argv) {
 int infile, status, oufile, pid, nread; int pid_processo;
 char buf[40]; char id[10];
 if (argc != 3)  {
  printf (" uso: nomeprogramma <inputFile> <outputFile> \n");
  exit (1);
 }  /* Apertura file outputFile*/
 if ((oufile=open(argv[2], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR))<0) {
  printf("Errore apertura outputFile %s\n:",argv[2]);
  exit(1);
 }/*Esecuzione fork*/
 if ((pid = fork()) == -1) {
  perror("fork");
  exit(1);
 } else if (pid == 0) {  /*Processo figlio*/
 /* Apertura file inputFile*/
  if ((infile=open(argv[1], O_RDONLY)) <0) {
   printf("Errore apertura inputFile da leggere %s\n:",argv[1]);
   exit(1);
  } /*legge i primi 40 caratteri*/
  if ( (nread = read(infile, buf, READLENGTH)) <= 0) {
   close(infile);
   exit(1);
  }
  /*scrive i primi 40 caratteri*/
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
  pid_processo = wait(&status); /*Attende che il figlio finisca di scrivere*/
  printf("Inizio processo padre\n");
  sprintf(id, "(PID:%d) Padre", getpid());
  if ( (write(oufile, id, strlen(id))) <= 0) {/*scrive i PID caratteri*/
   close(oufile);
   exit(1);
  }
 }
 close(oufile);
 printf("Fine processo padre\n");
 exit(0);
}

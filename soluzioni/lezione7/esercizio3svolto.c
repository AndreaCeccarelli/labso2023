#include <stdio.h> /* perror */
#include <errno.h> /* perror */
#include <unistd.h> /* write, lseek, close, exit */
#include <sys/types.h> /*open, lseek */
#include <sys/stat.h> /*open */
#include <fcntl.h> /*open*/

int main (int argc, char **argv) {
 int fd,pid, pid_processo; int nread,nwrite,status;
 char st1[256]; char st2[256]; /*Stringa lunga 256 caratteri*/
 if (argc != 2) {
   fprintf(stderr,"Uso: %s nomefile\n",argv[0]);
   exit(1);
 } /* Apertura del file in lettura e scrittura */
 if ((fd=open(argv[1], O_RDWR| O_CREAT, S_IRUSR | S_IWUSR))<0) {
   perror("opening argv[1]");
   exit(1);
 }
 if((pid=fork())<0) {  /*Creazione processo figlio*/
   perror("fork");
   exit(-1);
 } else if (pid==0) { /* Processo figlio */
   printf("Introduci una stringa e premi [Enter]\n");
   scanf("%s",st1);
   /* Il figlio eredita il descrittore fd dal padre */
   nwrite= write(fd,st1,strlen(st1));
   /* L' I/O pointer si e' spostato alla fine del file */
   exit(0);
 }
 else { /* pid > 0 : Processo padre */
 /* Attesa della terminazione del figlio */
   pid_processo = wait(&status);
 /* Con un solo figlio generato, pid_processo è uguale a pid */
 /* Riposizionamento all'inizio del file */
   lseek(fd,0,SEEK_SET);
   if( (nread = read(fd,st2,256)) <0) {
     perror("read ");
     exit(-1);
   }
   printf("Il padre ha letto la stringa %s\n",st2);
   close(fd);
 }
 exit(0);
}

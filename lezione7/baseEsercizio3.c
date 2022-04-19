lseek */
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
   //riceve la stringa (scanf)

   //effettua una write su fd

   exit(0);
 }
 else { /* pid > 0 : Processo padre */
  // Attende la terminazione del figlio

  //si riposiziona a inizio del file  (lseek, fseek)

  //effettua la read

   close(fd);
 }
 exit(0);
}

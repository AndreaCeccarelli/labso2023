#include  <stdlib.h>
#include  <stdio.h>
#include  <sys/types.h>
#include  <sys/stat.h>
#include   <fcntl.h>
#include   <unistd.h>
#define  FILE_MODE	 (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
int main(void){
  int  fdin, fdout, n, half_way, length_FILE1;
  int  c, buf[90];
  if((fdin=open("FILE1",O_RDWR|O_CREAT|O_TRUNC,FILE_MODE))<0)   //Crea FILE1  
    printf("FILE1 open error\n");             //in modalita' read-write
  if((fdout=open("FILE2",O_CREAT|O_RDWR|O_TRUNC,FILE_MODE))<0) //Apre il file
    printf("FILE2 open error\n");    //in cui copiare in modalita' write-only

  n=read(STDIN_FILENO,buf,90);   //leggo da standard input
  write(fdin,buf,n);             //scrivo su FILE1
  length_FILE1 = (int) lseek(fdin,0,SEEK_END);  //Controllo la lunghezza  di FILE1
  half_way = length_FILE1 / 2;
  n =  (int) lseek(fdin,-1,SEEK_END);        //mi posiziono alla fine di FILE1
 
  while ( n >= half_way)  {
       read(fdin, &c, 1);
       write(fdout, &c, 1);
       n= (int) lseek(fdin,-2,SEEK_CUR);
  }
  n = (int) lseek(fdin, 0, SEEK_SET);
  while(n < half_way)  {
	read(fdin, &c, 1);
	write(fdout, &c, 1);
	n = (int) lseek(fdin, 0, SEEK_CUR);
  } 
  lseek(fdout,0,SEEK_SET);
  while ( read(fdout, &c, 1) > 0) 
	write(STDOUT_FILENO, &c, 1); 
  printf("\n");
  exit(0); 
}


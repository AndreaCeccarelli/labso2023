/* include per stat */
#include <sys/stat.h>
#include <stdio.h> /* serve per la perror */
#include <stdlib.h> /* serve per la exit */
#include <string.h> /* serve per strlen */
#include <errno.h> /* serve per errno */
#include <unistd.h> /* serve per la write */

#define IFERROR(s,m) if((s)==-1) {perror(m); exit(errno);}
#define IFERROR3(s,m,c) if((s)==-1) {perror(m); c;}
#define WRITE(m) IFERROR(write(STDOUT,m,strlen(m)), m);
#define WRITELN(m) WRITE(m);WRITE("\n");
#define STDIN 0
#define STDOUT 1
#define STDERR 2

void printtype(char *);

int main(int argc, char *argv[]) {
	int i;
	/* per ciascun argomento */
	for (i=1; i<argc; i++)
		printtype(argv[i]); // stampa nome e tipo
		return(0);
	}

void printtype(char * filename) { 
	struct stat info;
	/* se non riesco ad aprile il file, scrivo un messaggio e ritorno al chiamante */
	IFERROR3(stat(filename, &info), filename, return);
	WRITE(filename);
	WRITE(": ");
	if( S_ISLNK(info.st_mode) ) { WRITE("symbolic link\n"); }
	else if( S_ISREG(info.st_mode) ) { WRITE("regular\n"); }
	else if( S_ISDIR(info.st_mode) ) { WRITE("directory\n"); }
	else if( S_ISCHR(info.st_mode) ) { WRITE("special character\n"); }  /* a device like a terminal */
	else if( S_ISBLK(info.st_mode) ) { WRITE("special block\n"); }          /* a device like a disk */
	else { WRITE("unknown type\n"); }
}


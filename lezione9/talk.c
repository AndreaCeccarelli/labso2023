#include <stdio.h>
#include <string.h>
#define READ 0
#define WRITE 1
char *phrase = "Stuff this in your pipe";
int main (void) {
  int fd [2], bytesRead;
  char message [100]; 
  pipe (fd); /* Create an unnamed pipe */
  if (fork () == 0) { /* Child, writer */
    close(fd[READ]); /* Close unused end */
    write (fd[WRITE], phrase, strlen (phrase) + 1); 
    close(fd[WRITE]); /* Close at the end */
  } else { /* Parent, reader*/
    close (fd[WRITE]); /* Close unused end */
    bytesRead = read (fd[READ], message, 100);
    printf ("Read %d bytes: %s\n", bytesRead, 
       message);
    close(fd[READ]); /* Close at the end */
  }
}


#include <stdio.h>

#include <fcntl.h>

int main (int argc, char *argv[]) {

  int fd;

  /* Crea un file con la open, fd è il file descriptor */
  /* il nome del file è in argv[1]! */

  fd = open( .... )

  dup2 (fd, 1);

  close (fd);

  //effettuare exec di argv[2]

  print("This should not be printed\n");

}

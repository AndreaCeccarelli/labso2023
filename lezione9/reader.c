#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h> /* For S_IFIFO */
#include <fcntl.h>

int readLine (int fd, char *str) {
/* Read a single '\0'-terminated line into str from fd */
/* Return 0 when the end-of-input is reached and 1 otherwise */
  int n;
  do { /* Read characters until '\0' or end-of-input */
     n = read (fd, str, 1); /* Read one character */
  } while (n > 0 && *str++ != '\0');
     return (n > 0); /* Return false if end-of-input */
  }
int main (void) {
  int fd;
  char str[100];
  /* Remove named pipe if it already exists */
  unlink("aPipe"); 
  /* Create named pipe */
  mknod ("aPipe", S_IFIFO, 0); 
  /* Change its permissions */
  chmod ("aPipe", 0660); 
  fd = open ("aPipe", O_RDONLY); /* Open it for reading */
  /* Display received messages */
  while (readLine (fd, str))
  printf ("%s\n", str);
  close (fd); /* Close pipe */
  unlink("aPipe"); /* Remove used pipe */
}

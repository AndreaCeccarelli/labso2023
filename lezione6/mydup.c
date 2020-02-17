#include <stdio.h>
#include <fcntl.h>
int main (void) {
  int fd1, fd2, fd3;
  fd1 = open ("test.txt", O_CREAT|O_RDWR, 0600);
  printf ("fd1 = %d\n", fd1);
  write (fd1, "what's", 6);
  fd2 = dup (fd1); /* Make a copy of fd1 */
  printf ("fd2 = %d\n", fd2);
  write (fd2, " up", 3);
  close (0); /* Close standard input */
  fd3 = dup (fd1); /*Make another copy of fd1*/
  printf ("fd3 = %d\n", fd3);
  write (0, " doc", 4);
  dup2 (3, 2); /*Dup channel 3 to channel 2 */
  write (2, "?\n", 2);
  return 0;
}


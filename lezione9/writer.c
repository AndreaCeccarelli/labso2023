#include <stdio.h>
#include <fcntl.h>
#include <string.h>
int main (void) {
  int fd, messageLen, i; char message [100];
  sprintf (message, "Hello from PID %d", getpid ()); /* Prepare message */
  messageLen = strlen (message) + 1;
  do { /* Keep trying to open the file until successful */
    fd = open ("aPipe", O_WRONLY); /* Open named pipe for writing */
    if (fd == -1) sleep (1); /* Try again in 1 second */
  } while (fd == -1);
for (i = 1; i <= 3; i++) { /* Send three messages */
    /* Write message down pipe */
    write (fd, message, messageLen); 
    sleep (3); /* Pause a while */
  }
  close (fd); /* Close pipe descriptor */
  return 0;
}


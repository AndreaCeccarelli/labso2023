#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h> /* For AFUNIX sockets */
#define DEFAULT_PROTOCOL 0

int writeRecipe (int fd) {
  static char* line1 = "spam, spam, spam, spam,";
  static char* line2 = "spam, and spam.";
  write (fd, line1, strlen (line1) + 1); /* Write first line */
  write (fd, line2, strlen (line2) + 1); /* Write second line */
}
int main (void) {
  int serverFd, clientFd, serverLen, clientLen;
  struct sockaddr_un serverUNIXAddress; /*Server address */
  struct sockaddr* serverSockAddrPtr; /*Ptr to server address*/
  struct sockaddr_un clientUNIXAddress; /*Client address */
  struct sockaddr* clientSockAddrPtr;/*Ptr to client address*/

  serverSockAddrPtr = (struct sockaddr*) &serverUNIXAddress;
  serverLen = sizeof (serverUNIXAddress);
  clientSockAddrPtr = (struct sockaddr*) &clientUNIXAddress;
  clientLen = sizeof (clientUNIXAddress);
  
  serverFd = socket (AF_UNIX, SOCK_STREAM, DEFAULT_PROTOCOL);
  serverUNIXAddress.sun_family = AF_UNIX; /* Set domain type */
  strcpy (serverUNIXAddress.sun_path, "recipe"); /* Set name */
  unlink ("recipe"); /* Remove file if it already exists */
  bind (serverFd, serverSockAddrPtr, serverLen);/*Create file*/
  listen (serverFd, 5); /* Maximum pending connection length */
 while (1) {/* Loop forever */ /* Accept a client connection */
   clientFd = accept (serverFd, clientSockAddrPtr, &clientLen);
   if (fork () == 0) { /* Create child to send receipe */
     writeRecipe (clientFd); /* Send the recipe */
     close (clientFd); /* Close the socket */
     exit (/* EXIT_SUCCESS */ 0); /* Terminate */
   } else
     close (clientFd); /* Close the client descriptor */
  }
}


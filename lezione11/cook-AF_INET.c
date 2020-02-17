#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> /* For AF_INET sockets */
#define DEFAULT_PROTOCOL 0

int readRecipe (int fd) {
  char str[200];
  while (readLine (fd, str))/*Read until input ends*/
  printf ("%s\n", str); /* Echo line from socket */
}

int readLine (int fd, char *str) {
  int n;
  do { /* Read characters until '\0' or end-of-input */
    n = read (fd, str, 1); /* Read one character */
  } while (n > 0 && *str++ != '\0');
  return (n > 0); /* Return false if end-of-input */
}


int main (void) {
  int clientFd, serverLen, result;
  unsigned short int port = 1025;
  struct sockaddr_in serverINETAddress;
  struct sockaddr* serverSockAddrPtr;
  serverSockAddrPtr=(struct sockaddr*)    
  &serverINETAddress;
  serverLen = sizeof (serverINETAddress);
  clientFd=socket(AF_INET,SOCK_STREAM,DEFAULT_PROTOCOL);
  serverINETAddress.sin_family = AF_INET;
  serverINETAddress.sin_port = htons (port);
  serverINETAddress.sin_addr.s_addr = htonl
  (INADDR_LOOPBACK);
  do {
   /* Loop until a connection is made with the server */
     result=connect(clientFd, serverSockAddrPtr, serverLen);
      if (result == -1) sleep (1);/* Wait, try again */
   } while (result == -1);

   readRecipe (clientFd); /* Read the recipe */
   close (clientFd); /* Close the socket */
   exit (/* EXIT_SUCCESS */ 0); /* Done */
}






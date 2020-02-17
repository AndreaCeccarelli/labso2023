#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h> /* For AF_UNIX sockets */
#define DEFAULT_PROTOCOL 0

int readRecipe (int fd) {
 char str[200];
 while (readLine (fd, str)) /* Read lines until end-of-input */
 printf ("%s\n", str); /* Echo line from socket */
}
int readLine (int fd, char *str) {
/* Read a single ’\0’-terminated line into str from fd */
 int n;
 do { /* Read characters until ’\0’ or end-of-input */
  n = read (fd, str, 1); /* Read one character */
 } while (n > 0 && *str++ != '\0');
 return (n > 0); } /* Return false if end-of-input */

int main (void) {
 int clientFd, serverLen, result;
 struct sockaddr_un serverUNIXAddress;
 struct sockaddr* serverSockAddrPtr;
 serverSockAddrPtr = (struct sockaddr*) &serverUNIXAddress;
 serverLen = sizeof (serverUNIXAddress);
 clientFd = socket (AF_UNIX, SOCK_STREAM, DEFAULT_PROTOCOL);
 serverUNIXAddress.sun_family = AF_UNIX; /* Server domain */
 strcpy (serverUNIXAddress.sun_path, "recipe");/*Server name*/
 do { /* Loop until a connection is made with the server */
  result = connect (clientFd, serverSockAddrPtr, serverLen);
  if (result == -1){
	printf("connection problem;re-try in 1 sec\n");
	sleep (1); /* Wait and then try again */
  }
 } while (result == -1);
	printf("reaching the sleep\n");
	sleep(20);
    readRecipe (clientFd); /* Read the recipe */
 close (clientFd); /* Close the socket */
 exit (/* EXIT_SUCCESS */ 0); /* Done */
}


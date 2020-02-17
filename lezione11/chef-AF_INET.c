#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> /* For AFINET sockets */
#define DEFAULT_PROTOCOL 0

int writeRecipe (int fd) {
  static char* line1 = "spam, spam, spam, spam,";
  static char* line2 = "spam, and spam.";
  write (fd, line1, strlen (line1) + 1); /*Write first   line*/
  write (fd, line2, strlen (line2) + 1); /* Write second   line */
}


int main (void) {

 int serverFd, clientFd, serverLen, clientLen;
 unsigned short int port = 1025;
 struct sockaddr_in serverINETAddress;/*Server address*/
 struct sockaddr_in clientINETAddress;/*Client address*/
 struct sockaddr* serverSockAddrPtr;/*Ptr to server address*/
 struct sockaddr* clientSockAddrPtr;/*Ptr to client address*/
 /* Ignore death-of-child signals to prevent zombies */

 signal (SIGCHLD, SIG_IGN);
 serverSockAddrPtr=(struct sockaddr*) &serverINETAddress;
 serverLen = sizeof(serverINETAddress);
 clientSockAddrPtr=(struct sockaddr*) &clientINETAddress;
 clientLen=sizeof (clientINETAddress);

/*Create a INET socket, bidirectional, default protocol */
 serverFd=socket (AF_INET, SOCK_STREAM, DEFAULT_PROTOCOL);
 serverINETAddress.sin_family = AF_INET;
 serverINETAddress.sin_port = htons (port);
 serverINETAddress.sin_addr.s_addr=htonl(INADDR_LOOPBACK);
 bind(serverFd, serverSockAddrPtr, serverLen);
 listen (serverFd, 5);

 while (1) {
   clientFd=accept(serverFd,clientSockAddrPtr,&clientLen);
   if (fork () == 0) { /* Create child to send receipe */
     writeRecipe (clientFd); /* Send the recipe */
     close (clientFd); /* Close the socket */
     exit (/* EXIT_SUCCESS */ 0); /* Terminate */
   } else
     close (clientFd); /* Close the client descriptor */
   }

}


#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


int main(int argc, char *argv[]){
     int sockfd, newsockfd, portno, clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;

	//TODO: create socket AF_INET on port argv[1]

	//TODO: bind
	//TODO: listen
	//TODO: accept


     n = read(newsockfd,buffer,255);

     if (n < 0)
		//TODO: print error message, exit

     printf("Here is the message: %s\n",buffer);
     n = write(newsockfd,"I got your message",18);

     if (n < 0)
		//TODO: print error message, exit

     return 0;
}


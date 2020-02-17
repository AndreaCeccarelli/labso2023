#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>



void error(char *msg){
    perror(msg);
    exit(0);
}

 
int main(int argc, char *argv[]){
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }

	//TODO: riceve numero di porta da argv[2], lo memorizza in portno

	//TODO: crea socket (inizializza sockfd)
	//					(inizializza server con argv[1])
	//					bla bla bla... creazione socket AF_INET


    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

	    printf("Please enter the message: ");
		//TODO: inserire un messaggio da tastiera
	
		//TODO: scrivere messaggio sulla socket	

		//TODO: leggere messaggio sulla socket
	
		//TODO: stampare messaggio a video

    return 0;

}


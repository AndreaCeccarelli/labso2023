#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> /* For AF_INET sockets */

#define REQUEST "GET / HTTP/1.1\r\n\r\n" /* DEFAULT HTTP GET REQUEST */

int main (void) {
	int fd_skt, nread;
	char buf[1024];
	//create socket AF_INET on port 80, address 150.217.6.71
	
	//connect to target server

	write(fd_skt, REQUEST, strlen(REQUEST)); /* SEND HTTP REQUEST */
	nread = read(fd_skt, buf, sizeof(buf));

	//print values read on stdout
	

	close(fd_skt);
	return 0;
}


 

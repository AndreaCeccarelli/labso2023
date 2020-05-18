#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> /* For AF_INET sockets */
#define REQUEST "GET / HTTP/1.1\r\n\r\n" /* DEFAULT HTTP GET REQUEST */
int main (void) {
	struct sockaddr_in sa; 
	int fd_skt, nread;
	char buf[1024];
	sa.sin_family = AF_INET;
	sa.sin_port = htons(80); /* DEFAULT HTTP SERVER PORT */
	sa.sin_addr.s_addr = inet_addr("150.217.6.125");
	fd_skt =socket(AF_INET, SOCK_STREAM, 0);
	connect(fd_skt, (struct sockaddr*)&sa, sizeof(sa));
	write(fd_skt, REQUEST, strlen(REQUEST)); /* SEND HTTP REQUEST */
	nread = read(fd_skt, buf, sizeof(buf));
	write(1, buf, nread); /* WRITE TO STDOUT */
	close(fd_skt);
	return 0;
} 

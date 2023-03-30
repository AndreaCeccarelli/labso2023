#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	char* buf;
	int offset=0, fd=0, n=0;
	buf="This is an apple.";
	fd= open("example.txt", O_RDWR|O_CREAT, 0777);
	n=write(fd, buf, 17);
	offset=lseek(fd, 9, SEEK_SET);
	n=write(fd, " sam", 4);
	printf("%d\n", n);
	printf("%ld\n", sizeof(buf));
}

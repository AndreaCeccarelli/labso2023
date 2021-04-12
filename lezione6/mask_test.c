#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

void main(){
 int fd;
 fd=open("test1", O_CREAT, 0777);
 close(fd);

 umask(000);
 fd=open("test2", O_CREAT, 0777);
 close(fd);

 umask(0022);
 fd=open("test3", O_CREAT, 0777);
 close(fd);

 umask(0033);
 fd=open("test4", O_CREAT, 0777);
 close(fd);
}

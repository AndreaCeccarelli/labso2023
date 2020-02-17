#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
int main(void) {
	int fd;
	fd = open ("nonexist.txt", O_RDONLY); /* error */
	if (fd == -1) {
			printf ("errno = %d\n", errno);
			perror ("main");
	};
	fd = open ("/", O_WRONLY); /* another error */
	if (fd == -1) {
			printf ("errno = %d\n", errno);
			perror ("main");
	};
	/* Execute a successful system call */
	fd= open ("nonexist.txt", O_RDONLY | O_CREAT, 0666);
	//try different values to see the effect of umask
	printf ("errno = %d\n", errno); /* Display */
	perror ("main");
	errno = 0; /* Manually reset error variable */
	perror ("main");
	return 0;
}

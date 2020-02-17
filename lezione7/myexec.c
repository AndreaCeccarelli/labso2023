#include <stdio.h>
#include <unistd.h>
int main (void) {
   printf("I'm process %d and I'm about to exec an ls -l\n", getpid());
  execl("/bin/ls", "ls", "-l", NULL); 
  printf("This line should never be executed\n");
}


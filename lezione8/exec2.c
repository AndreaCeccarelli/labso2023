#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
       if (argc < 2) {
                   printf("usage: exec2 prog_name [<option>]\n");
                   return -1;
      }
       if (argc==2){
                   execlp(argv[1], argv[1], NULL);
      }  else {
                   execlp(argv[1], argv[1], argv[2], NULL);
      }
       printf("Should never execute");
       return 0;
}


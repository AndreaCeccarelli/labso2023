#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

main( ) {
   int *pi=NULL;
   printf("int %d\n",sizeof(int));
   printf("float %d\n",sizeof(float));

   pi= (int*)(calloc(INT_MAX, INT_MAX));

   free(pi); /* deallocazione del vettore*/ 
} 


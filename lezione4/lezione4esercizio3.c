#include <stdio.h>
#include <stdlib.h>
typedef char parola[20];
main( ) {
	parola w, *p; 
	int i, j, N; 
	printf("Quante parole? "); 
	scanf("%d\n", &N); 
	fflush(stdin); /* allocazione del vettore */ 
	p = (parola *) malloc(N * sizeof(parola)); /* lettura della sequenza */
	for (i=0; i< N; i++){
		gets(p[i]);
     }
   for(i=N-1; i>=0; i--) {
	j=19; 
	do 
		j--; 
	while(p[i][j] != '\0'); 
	for(j--; j>=0; j--) 
		printf("%c", p[i][j]); 
		printf("\n"); 
	} 
	free(p); /* deallocazione del vettore*/ 
} 



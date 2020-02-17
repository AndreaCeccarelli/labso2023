#include <stdio.h>
int main(void) {
	if( __STDC__ )
			printf("Compilatore ANSI C \n");
	else printf("Compilatore non ANSI C \n");
	printf("oggi %s, alle %s\n", __DATE__ , __TIME__ );
	printf("nome del file = %s, siamo alla linea: %d\n", __FILE__ , __LINE__ );
	return 0;
}


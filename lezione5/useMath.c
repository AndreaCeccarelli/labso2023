#include <stdio.h>
#include <math.h>

int main()
{
//alcune prove: 
// cc -lm useMath.c -o nomeoggetto 
// cc -static -lm useMath.c -o nomeoggetto
// cc -static useMath.c -lm -o nomeoggetto

// Investigare con "nm nomeoggetto.o|grep 
// fmod" il link a fmod:
//   - per il file oggetto (compilare: gcc -c useMath)
//   - per eseguibile con linking statico e dinamico

//Verificare dimensione eseguibile con linking statico e dinamico

	int k= fmod (3,2);
	printf("\n %d \n", k);
	return 0;
} 

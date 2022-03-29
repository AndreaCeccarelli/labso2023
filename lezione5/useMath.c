#include <stdio.h>
#include <math.h>

int main()
{
//alcune prove:
// cc -lm useMath.c -o nomeoggetto
// cc -static -lm useMath.c -o nomeoggetto
// cc -static useMath.c -lm -o nomeoggetto
//Verificare dimensione eseguibile con linking statico e dinamico

// Verificare con "nm useMath.o" che gcc -c crea solo tabella dei simboli:


        int k= fmod (3,2);
        printf("\n %d \n", k);
        return 0;
}

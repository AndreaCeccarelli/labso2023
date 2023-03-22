#include <stdio.h>
#include <math.h>

int main()
{
//alcune prove:
// cc useMath.c -lm -o nomeoggetto
// cc useMath.c -static -lm  -o nomeoggetto
// cc useMath.c -static  -lm -o nomeoggetto
//Verificare dimensione eseguibile con linking statico e dinamico

        int k= fmod (3,2);
        printf("\n %d \n", k);
        return 0;
}

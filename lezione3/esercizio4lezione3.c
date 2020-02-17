#include <stdio.h>
#define MAX 10
int array[MAX+1], count;
int largest(int *x);
int main()
{
 /*input non piu' di MAX valori da tastiera*/
 /*per terminare l'inserimento digitare lo zero*/

 for (count=0; count < MAX; count++)
 {
 printf("\nInserire un valore intero");
 scanf("%d", &array[count]);
 if (array[count]==0)
 count=MAX;
 }
 array[MAX]=0;

 /*chiama la funzione e visualizza il valore di ritorno*/
 printf("\n Valore massimo=%d", largest(array));
 return 0;
}

/*La funzione largest() restituisce il valore massimo in un array di interi*/
int largest(int *x)
{
 int count, biggest =-12000;
 for (count =0; x[count] != 0; count++)
 { 
 if (x[count]>biggest)
 biggest = x[count];
 	}
 return biggest;
}




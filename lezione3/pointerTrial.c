#include <stdio.h> 
 int main( ) { 
    int alfa = 4; int beta = 7; int *pointer; pointer = &alfa; 
    printf("alfa -> %d, beta -> %d, pointer -> %d \n", alfa, beta, 			pointer); 
    beta = *pointer; 
	printf("alfa -> %d, beta -> %d, pointer -> %d \n", alfa, beta, 			pointer); 
	alfa = pointer; 
	printf("alfa -> %d, beta -> %d, pointer -> %d \n", alfa, beta, 			pointer); 
	*pointer = 5; 
	printf("alfa -> %d, beta -> %d, pointer -> %d \n", alfa, beta, 			pointer); 
}

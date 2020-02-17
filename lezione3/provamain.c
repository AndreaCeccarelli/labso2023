#include <stdio.h>
int main( int argc, char *argv[] ) {
 int i;
 printf( "Il programma si chiama %s ", argv[0] );
 printf( "ed i suoi %i argomenti sono:\n", argc-1 );
 for ( i = 1; i < argc ; i++ ) {
   printf( "argomento n. %d: %s\n", i, argv[i] );
 }
 return 0;
}

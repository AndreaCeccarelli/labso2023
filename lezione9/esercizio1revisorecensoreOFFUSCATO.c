#include <fcntl.h>
#include <stdlib.h>
void main( int argc, char *argv[] ) {
	int pipe_p1p2[2], pipe_p2p0[2]; // pipe_p1p2: comunicazione fra revisore e censore
	// pipe_p2p0: comunicazione fra censore e pubblicatore
	int pid1, pid2, filein, status;
	char c, C;
	if( argc<3 ) exit( -1 );
	if( pipe( pipe_p1p2 )<0 ) exit( -2 );
	if( pipe( pipe_p2p0 )<0 ) exit( -3 );
	if( ( pid1=fork() )<0 ) exit( -4 );

	if( pid1==0 ) {
		// codice revisore
		[...]	// il revisore chiude la comunicazione fra pubblicatore e censore
		[...]	// il revisore chiude la comunicazione fra pubblicatore e censore
		[...] // il revisore chiude lato lettura comunicazione con il censore
		[...] // il revisore apre in sola lettura il file in argv[2]

		while( read( filein, &C, 1 ) )
			[..] // il revisore invia (scrive) 1 carattere alla volta (cioè "&C") al censore
			[..] //chiude la pipe usata
			[..] //chiude il file
			[..] //exit
	}else {
		if( ( pid2=fork() )<0 ) exit( -5 );
		if( pid2==0 ) {
			// codice censore
			[...] // il censore legge dal revisore e scrive al pubblicatore
			[...] // quindi c'è da chiudere i canali di pipe giusti (sono 2)
			c = argv[1][0]; //carattere da cancellare dal testo
			while( read( pipe_p1p2[0], &C, 1 ) ){
				if( C!=c )
					write( pipe_p2p0[1], &C, 1 );
			}
			close( pipe_p2p0[1] );
			exit( 0 );
		 }
		else {
			// codice pubblicatore
			[...]; //chiude tutti i canali di pipe non usati (sono 3)

			while( read( pipe_p2p0[0], &C, 1 ) ) {
				[...] // il pubblicatore stampa i caratteri ricevuti dal censore
			}
	 		close( pipe_p2p0[0] );
		}
	}
	wait(&status);
	wait(&status);
}



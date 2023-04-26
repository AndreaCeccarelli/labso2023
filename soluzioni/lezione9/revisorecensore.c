#include <fcntl.h>
#include <stdlib.h>
void main( int argc, char *argv[] ) {
	int pipe_p1p2[2], pipe_p2p0[2]; 	// pipe_p1p2: comunicazione fra revisore e censore
					// pipe_p2p0: comunicazione fra censore e pubblicatore
	int pid1, pid2, filein, status;
	char c, C;
	if( argc<3 ) exit( -1 );
	if( pipe( pipe_p1p2 )<0 ) exit( -2 );
	if( pipe( pipe_p2p0 )<0 ) exit( -3 );
	if( ( pid1=fork() )<0 ) exit( -4 );
	if( pid1==0 ) {
		// codice revisore
		close( pipe_p2p0[1] );	// il revisore chiude la comunicazione fra pubblicatore e censore
		close( pipe_p2p0[0] );	// il revisore chiude la comunicazione fra pubblicatore e censore
		close( pipe_p1p2[0] );	// il revisore chiude lato lettura comunicazione con il censore
		filein=open( argv[2], O_RDONLY );
		if( filein<=0 ) exit( -5 );
		while( read( filein, &C, 1 ) )
			write( pipe_p1p2[1], &C, 1 ); // il revisore invia 1 carattere alla volta al censore
		close( pipe_p1p2[1] );
		close( filein );
	//	exit( 0 );
	}else {
		if( ( pid2=fork() )<0 ) exit( -5 );
		if( pid2==0 ) {
			// codice censore
			close( pipe_p1p2[1] ); // il censore legge dal revisore e scrive al pubblicatore
			close( pipe_p2p0[0] );
			c = argv[1][0];
			while( read( pipe_p1p2[0], &C, 1 ) ){
				if( C!=c )
					write( pipe_p2p0[1], &C, 1 );
			}
			close( pipe_p2p0[1] );
//			exit( 0 );
		 }
		else {
			// codice pubblicatore
			close( pipe_p1p2[0] );
			close( pipe_p1p2[1] );
			close( pipe_p2p0[1] );
			while( read( pipe_p2p0[0], &C, 1 ) ) {
				write( 1, &C, 1 ); // il pubblicatore stampa i caratteri ricevuti dal censore
			}
	 		close( pipe_p2p0[0] );
		}
	}
	wait(&status);
	wait(&status);
}

#include <stdio.h>
#define RECORD 10
int main(void) {
	char ac[RECORD];
	FILE *pf;
	int iQta;
	int iPosizione1;
	int iPosizione2;
	pf = fopen( "mio_file", "r+" ); 
	while(1) { /* Ciclo senza fine */
/*Salva la posizione del puntatore interno al file */
/* prima di eseguire la lettura. */
			iPosizione1 = ftell( pf );


iQta = fread( ac, 1, RECORD, pf );
if (iQta == 0) {
	break; /* Termina il ciclo */
}
/*Salva la posizione del puntatore interno al file*/
/* dopo la lettura. */
iPosizione2 = ftell( pf );
/*Sposta il puntatore alla posizione precedente */
/* alla lettura. */
fseek( pf, iPosizione1, SEEK_SET);
/* Esegue modifiche nei dati, per esempio mette un */
/* punto esclamativo all'inizio. */
ac[0] = '!';

/*Riscrive il record modificato. */
			fwrite( ac, 1, iQta, pf );
/*Riporta il puntatore interno al file alla */
/*posizione corretta per eseguire la */
/* prossima lettura. */
			fseek( pf, iPosizione2, SEEK_SET);
	}
fclose( pf );
return 0;
}


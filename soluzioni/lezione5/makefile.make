all: mainFinal

mainFinal: mainFinal.o A.o B.o
        cc mainFinal.o A.o B.o -o mainFinal

mainFinal.o: mainFinal.c
        cc -c mainFinal.c

B.o: B.h
        cc -c B.c

A.o: A.h B.h
        cc -c A.c

clean:
        mv progetto/src/* .
        mv progetto/include/* .
        rm -r progetto

install:
        mkdir progetto
        mkdir progetto/include
        mkdir progetto/src
        mkdir progetto/bin
        cp mainFinal progetto/bin
        cp *.c progetto/src
        cp makefile.make progetto
        cp *.h progetto/include
        
        

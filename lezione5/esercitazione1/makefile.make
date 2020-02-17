versioneFinale1: mainFinal.o A.o B.o
	gcc -o versioneFinale1 mainFinal.o A.o B.o

mainFinal.o: mainFinal.c A.h
	gcc -c mainFinal.c

A.o: A.c A.h B.h F.h
	gcc -c A.c

B.o: B.c B.h F.h
	gcc -c B.c


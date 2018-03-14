readmymind: readmymind.o io.o actions.o cards.o
	gcc -std=c99 -Wall -Wextra -g readmymind.o io.o actions.o cards.o -o readmymind

readmymind.o: readmymind.c readmymind.h
	gcc -std=c99 -Wall -Wextra -g readmymind.c -c -o readmymind.o

io.o: io.c readmymind.h
	gcc -std=c99 -Wall -Wextra -g io.c -c -o io.o

actions.o: actions.c readmymind.h
	gcc -std=c99 -Wall -Wextra -g actions.c -c -o actions.o

cards.o: cards.c readmymind.h
	gcc -std=c99 -Wall -Wextra -g cards.c -c -o cards.o 

clean:
	rm *.o readmymind

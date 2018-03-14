readmymind: readmymind.o linkedlist.o cards.o io.o actions.o
	gcc -std=c99 -Wall -Wextra -g readmymind.o linkedlist.o cards.o io.o actions.o -o readmymind 

readmymind.o: readmymind.c readmymind.h
	gcc -std=c99 -Wall -Wextra -g readmymind.c -c -o readmymind.o

linkedlist.o: linkedlist.c readmymind.h
	gcc -std=c99 -Wall -Wextra -g linkedlist.c -c -o linkedlist.o

cards.o: cards.c readmymind.h
	gcc -std=c99 -Wall -Wextra -g cards.c -c -o cards.o

io.o: io.c readmymind.h
	gcc -std=c99 -Wall -Wextra -g io.c -c -o io.o

actions.o: actions.c readmymind.h
	gcc -std=c99 -Wall -Wextra -g actions.c -c -o actions.o

clean:
	rm *.o readmymind

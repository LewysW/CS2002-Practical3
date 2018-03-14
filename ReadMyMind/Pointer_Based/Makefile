readmymind: readmymind.o linkedlist.o cards.o
	gcc -std=c99 -Wall -Wextra -g readmymind.o linkedlist.o cards.o -o readmymind 

readmymind.o: readmymind.c readmymind.h
	gcc -std=c99 -Wall -Wextra -g readmymind.c -c -o readmymind.o

linkedlist.o: linkedlist.c readmymind.h
	gcc -std=c99 -Wall -Wextra -g linkedlist.c -c -o linkedlist.o

cards.o: cards.c readmymind.h
	gcc -std=c99 -Wall -Wextra -g cards.c -c -o cards.o

clean:
	rm *.o readmymind

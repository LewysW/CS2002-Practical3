readmymind: readmymind.o
	gcc -std=c99 -Wall -Wextra -g readmymind.o -o readmymind

readmymind.o: readmymind.c cards.h
	gcc -std=c99 -Wall -Wextra -g readmymind.c -c -o readmymind.o

clean:
	rm readmymind.o readmymind

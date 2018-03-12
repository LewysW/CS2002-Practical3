card_trick: readmymind.o
	gcc -std=c99 -Wall -Wextra -g readmymind.o -o readmymind

main.o: readmymind.c cards.h
	gcc -std=c99 -Wall -Wextra -g readmymind.c -c -o readmymind.o

clean:
	rm readmymind.o readmymind

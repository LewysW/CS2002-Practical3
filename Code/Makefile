card_trick: main.o
	clang -std=c99 -Wall -Wextra -g main.o -o card_trick

main.o: main.c cards.h
	clang -std=c99 -Wall -Wextra -g main.c -c -o main.o

clean:
	rm main.o card_trick

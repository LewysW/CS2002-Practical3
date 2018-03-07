#ifndef HEADER
#define HEADER
int getUserCol();
int isValidInp(char input[]);
int charToInt(char input[]);

struct Card {
    char suit;
    int rank;
};

typedef struct Deck {
    struct Card cards [52];
};

struct Card getCard(int suitNum, int rank);
struct Deck getDeck();
#endif

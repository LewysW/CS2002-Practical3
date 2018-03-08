#ifndef HEADER
#define HEADER
int getUserCol();
int isValidInp(char input[]);
int charToInt(char input[]);

#define suitSize 13
#define deckSize 52
#define columnSize 7
#define numColumns 3
#define spade 1
#define heart 2
#define club 3
#define diamond 4

struct Card {
    int suit;
    int rank;
};

typedef struct Deck {
    struct Card cards [deckSize];
};

struct Column {
    struct Card cards[columnSize];
};

typedef struct Columns {
    struct Column column[numColumns];
};

struct Card getCard(int suit, int rank);
struct Deck getDeck();
struct Columns fill(struct Deck deck);
#endif

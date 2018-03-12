#ifndef HEADER
#define HEADER

#define SUIT_SIZE 13
#define DECK_SIZE 52
#define NUM_SUITS 4
#define COLUMN_SIZE 7
#define NUM_COLUMNS 3

struct Card {
    int suit;
    int rank;
};

typedef struct Deck {
    struct Card cards [DECK_SIZE];
}Deck;

typedef struct Column {
    struct Card cards[COLUMN_SIZE];
}Column;

typedef struct Columns {
    struct Column column[NUM_COLUMNS];
}Columns;

int getUserCol();
bool isValidInp(char input[]);
int charToInt(char input[]);
struct Card getCard(int suit, int rank);
struct Deck getDeck();
struct Columns fill(struct Deck deck);
void printCols(struct Columns columns);
void printCentreCard(struct Columns columns);
struct Columns gather(struct Columns columns, int col);
struct Columns deal(struct Columns columns);
#endif

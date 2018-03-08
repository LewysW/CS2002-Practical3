#ifndef HEADER
#define HEADER

#define SUIT_SIZE 13
#define DECK_SIZE 52
#define NUM_SUITS 4
#define COLUMN_SIZE 7
#define NUM_COLUMNS 3
#define SPADE 1
#define HEART 2
#define DIAMOND 3
#define CLUB 4
const char* CARD_FACES[NUM_SUITS][SUIT_SIZE] = {\
                                            {"🂡","🂢","🂣","🂤","🂥","🂦","🂧","🂨","🂩","🂪","🂫","🂭","🂮"},\
                                            {"🂱","🂲","🂳","🂴","🂵","🂶","🂷","🂸","🂹","🂺","🂻","🂽","🂾"},\
                                            {"🃁","🃂","🃃","🃄","🃅","🃆","🃇","🃈","🃉","🃊","🃋","🃍","🃎"},\
                                            {"🃑","🃒","🃓","🃔","🃕","🃖","🃗","🃘","🃙","🃚","🃛","🃝","🃞"}\
                                        };

const char* SUITS[NUM_SUITS] = {"♠", "♥", "♦", "♣"};
const char* RANKS[SUIT_SIZE] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

struct Card {
    int suit;
    int rank;
};

typedef struct Deck {
    struct Card cards [DECK_SIZE];
};

struct Column {
    struct Card cards[COLUMN_SIZE];
};

typedef struct Columns {
    struct Column column[NUM_COLUMNS];
};

int getUserCol();
bool isValidInp(char input[]);
int charToInt(char input[]);
struct Card getCard(int suit, int rank);
struct Deck getDeck();
struct Columns fill(struct Deck deck);
void printCols(struct Columns columns);
#endif

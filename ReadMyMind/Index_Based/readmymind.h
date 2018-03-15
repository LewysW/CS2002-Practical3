#ifndef HEADER
#define HEADER

#define SUIT_SIZE 13
#define DECK_SIZE 52
#define NUM_SUITS 4
#define COLUMN_SIZE 7
#define NUM_COLUMNS 3

/* Represents a card and stores its suit and rank as a number from 0 to 3 and
0 to 12 respectively */
struct Card {
    int suit;
    int rank;
};

/*
Represents a deck using a list of cards with the size DECK_SIZE
*/
typedef struct Deck {
    struct Card cards [DECK_SIZE];
}Deck;

/*
Represents a column of seven cards using a list of cards of size COLUMN_SIZE
*/
typedef struct Column {
    struct Card cards[COLUMN_SIZE];
}Column;

/*
Represents the three columns of 21 cards using a list of columns of size NUM_COLUMNS
*/
typedef struct Columns {
    struct Column column[NUM_COLUMNS];
}Columns;

// Prompts user to enter the column that their card is in.
int getUserCol();

// Validates user's input
bool isValidInp(char* input);

// Converts the user's input to an integer
int charToInt(char input);

// Creates and returns a card object given an integer suit and rank
struct Card getCard(int suit, int rank);

// Creates and returns a deck populated with 52 cards
struct Deck getDeck();

// Fills a Columns struct with 21 random unique cards and returns the columns
struct Columns fill(struct Deck deck);

// Prints the contents of a columns struct
void printCols(struct Columns columns);

// Prints the centre card of a columns struct
void printCentreCard(struct Columns columns);

/*
'Gathers' the user's columns by placing the selected column in the middle of a
new columns struct
*/
struct Columns gather(struct Columns columns, int col);

/* Deals the cards of a columns struct from columns into rows and returns the new
resulting columns struct */
struct Columns deal(struct Columns columns);
#endif

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "cards.h"

int main() {
    struct Deck deck = getDeck();
    struct Columns columns = fill(deck);
    int col;

    for (int i = 0; i < 4; i++) {
        printCols(columns);
        col = getUserCol();
        columns = gather(columns, col);
        columns = deal(columns);
    }

    printCentreCard(columns);
    return 0;
}

/**
Prompts the user to enter a letter corresponding to the column that their card
resides in.
*/
int getUserCol() {
    //Stores the users input
    char input[10];

    do {
        printf("Which column does your card sit in? (L, M, R)\n");

        //Takes a maximum of 10 characters (9 from the user excluding the \0)
        fgets(input, 10, stdin);

        //Repeats while the input is invalid.
    } while (!isValidInp(input));

    // Returns an integer from 0 to 2 corresponding to the character chosen by the user.
    return charToInt(input);
}

/*
Iterates over the character(s) input by the user and returns a boolean signifying
whether the user's input is valid.

@input - array of characters entered by user.
*/
bool isValidInp(char input[]) {
    // Valid characters.
    static const char valid[6] = {'l', 'm', 'r', 'L', 'M', 'R'};

    /* If the user's input is greater than 2 (their character plus the NULL
    terminator (\0) character) then return false.
    */
    if (strlen(input) > 2) return false;

    /*
    Iterates over the list of valid characters and checks each against the character
    input by the user to see if the input is valid.

    Used size_t to make i and unsigned int to avoid a comparison between a signed and unsigned int
    */
    for (size_t i = 0; i < sizeof(valid)/sizeof(valid[0]); i++) {
        if (input[0] == valid[i]) {
            assert(input != NULL);
            return true;
        }
    }

    return false;
}

/*
Converts the user's column character into a corresponding int value to be easier
to iterate over in the program.
*/
int charToInt(char input[]) {
    //l/L corresponds to 0
    if (input[0] == 'l' || input[0] == 'L') {
        return 0;
    //m/M corresponds to 1
    } else if (input[0] == 'm' || input[0] == 'M') {
        return 1;
    //r/R corresponds to 2
    } else if (input[0] == 'r' || input[0] == 'R') {
        return 2;
    }

    // Should never happen but will terminate program if it does.
    assert(!"Uncreachable Code");
}

/*
Generates a deck struct whose cards are populated with integers representing
the suit (0 - 3) and rank (0 - 12) of the current card.
*/
struct Deck getDeck() {
    struct Deck deck;
    int rank;
    int suit;

    //Iterates over every card in the deck and sets the suit and rank.
    for (int  i = 0; i < DECK_SIZE; i++) {
        suit = (i / SUIT_SIZE);
        rank = (i % SUIT_SIZE);

        //Creates card using getCard and assigns it to card array in deck struct.
        deck.cards[i] = getCard(suit, rank);
    }

    return deck;
}

/*
Initialises a card struct by assigning its suit and rank.
*/
struct Card getCard(int suit, int rank) {
    struct Card card;
    card.suit = suit;
    card.rank = rank;

    return card;
}

struct Columns fill(struct Deck deck) {
    struct Columns columns;
    int chosen[DECK_SIZE] = { 0 };
    int counter = 0;
    srand(time(NULL));
    int random = 0;

    // Repeats until 21 (3 * 7) unique cards have been assigned to columns
    while (counter < (NUM_COLUMNS * COLUMN_SIZE)) {
        //Generates a random number between
        random = rand()%DECK_SIZE;
        if (chosen[random] == 0) {
            //TODO change to make more readable
            /* Counter / columnSize finds the current column,
            counter % columnSize calculates current card in column.
            The random card selected is assigned to the card position in this column */
            columns.column[counter / COLUMN_SIZE].cards[counter % COLUMN_SIZE] = deck.cards[random];
            // Increments number of cards assign to columns
            counter++;
            // Sets card to used so it won't be assigned twice.
            chosen[random] = 1;
        }
    }

    return columns;
}

/*
Iterates over a Columns struct and prints outs the cards in each column.
*/
void printCols(struct Columns columns) {
    int suit;
    int rank;

    //Iterates over column size in outer loop and number of columns in inner loop
    //so that cards are printed in the same order as they would be dealt in real life.
    for (int i = 0; i < COLUMN_SIZE; i++) {
        for (int j = 0; j < NUM_COLUMNS; j++) {

            //Gets the suit and rank at the
            suit = columns.column[j].cards[i].suit;
            rank = columns.column[j].cards[i].rank;

            //Formatting to add an extra space after cards with rank 10.
            if (rank == 9) printf("%s%s ", RANKS[rank], SUITS[suit]);
            else printf("%s%s  ", RANKS[rank], SUITS[suit]);
        }

        printf("\n");
    }
}

/*
Prints the card in the centre of the columns.

@columns - of which to print the centre card.
*/
void printCentreCard(struct Columns columns) {
    int suit = columns.column[NUM_COLUMNS / 2].cards[COLUMN_SIZE / 2].suit;
    int rank = columns.column[NUM_COLUMNS / 2].cards[COLUMN_SIZE / 2].rank;
    printf("Your card is the %s%s\n", RANKS[rank], SUITS[suit]);
}

/*
Performs the gather stage of the trick by creating a new set of columns with the
column chosen by the user in the middle.
*/
struct Columns gather(struct Columns columns, int col) {
    struct Columns newColumns;
    //Sets new middle column to the column chosen by the user.
    newColumns.column[NUM_COLUMNS / 2] = columns.column[col];
    int index = 0;

    //Assigns each of the remaining columns to a location in the outer columns.
    for (int i = 0; i < NUM_COLUMNS; i++) {
        if (i != col) {
            newColumns.column[index] = columns.column[i];
            index += 2;
        }
    }

    return newColumns;

}

struct Columns deal(struct Columns columns) {
    struct Columns newColumns;
    int column = 0;
    int row = -1;
    int cardsDealt = 0;

    for (int i = 0; i < NUM_COLUMNS; i++) {
        for (int j = 0; j < COLUMN_SIZE; j++) {
            column = (i + j) % NUM_COLUMNS;
            if (cardsDealt % NUM_COLUMNS == 0) row++;
            newColumns.column[column].cards[row] = columns.column[i].cards[j];
            cardsDealt++;
        }

    }

    return newColumns;
}

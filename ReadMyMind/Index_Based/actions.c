#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "readmymind.h"

/*
Initialises a Columns struct with 21 random and unique cards from the deck of
52 cards.

@deck - deck of cards to use for initialisation.
*/
struct Columns fill(struct Deck deck) {
    //Declares Columns struct to be returned with 21 random cards.
    struct Columns columns;

    //Fills array of bools signifying cards that have been chosen with value of false
    bool chosen[DECK_SIZE] = { false };

    //Stores number of cards chosen
    int counter = 0;

    //Sets random seed.
    srand(time(NULL));
    int random = 0;

    // Repeats until 21 - (3 * 7) - unique cards have been assigned to columns
    while (counter < (NUM_COLUMNS * COLUMN_SIZE)) {
        //Generates a random number between 0 and size of deck
        random = rand()%DECK_SIZE;

        //If the current card has not been chosen already
        if (!chosen[random]) {

            //Calculate column and card indices to store card.
            int column = counter / COLUMN_SIZE;
            int card = counter % COLUMN_SIZE;

            //assigns card to columns and increments number chosen.
            columns.column[column].cards[card] = deck.cards[random];
            counter++;

            // Sets card to chosen so it won't be assigned twice.
            chosen[random] = true;
        }
    }

    return columns;
}

/*
Performs the gather stage of the trick by creating a new set of columns with the
column chosen by the user placed in the centre.
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

/*
Deals the cards into 3 new columns horizontally from left to right.

@columns - columns containing cards to be dealt into 3 new columns.
*/
struct Columns deal(struct Columns columns) {
    //New Columns
    struct Columns newColumns;

    //Sets initial column and row (negative to start as it is incremented)
    int column = 0;
    int row = -1;

    //Current number of cards dealt
    int cardsDealt = 0;

    //Iterates over number of columns
    for (int i = 0; i < NUM_COLUMNS; i++) {
        //Iterates over size of column
        for (int j = 0; j < COLUMN_SIZE; j++) {

            //Calculates current column (not equal to i as cards are dealt horizontally
            //not vertically)
            column = (i + j) % NUM_COLUMNS;

            //Increments row if the number of cards dealt is a multiple of the number of columns.
            if (cardsDealt % NUM_COLUMNS == 0) row++;
            newColumns.column[column].cards[row] = columns.column[i].cards[j];
            cardsDealt++;
        }

    }

    return newColumns;
}

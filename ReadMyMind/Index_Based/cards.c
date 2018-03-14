#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include "readmymind.h"

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

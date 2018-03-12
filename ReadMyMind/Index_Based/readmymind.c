#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "readmymind.h"

int main() {
    /*Declares a deck of 52 cards, the columns to store the 21 cards and an int
    to store the user's choice of column. */
    struct Deck deck = getDeck();
    struct Columns columns = fill(deck);
    int col;

    /* Repeats 3 times, each time printing the 3 columns of 7 cards and prompting
     the user to enter their column of choice signifying where their card is.
     Cards are gathered and re-dealt into new columns before being printed */
    for (int i = 0; i < 3; i++) {
        printCols(columns);
        col = getUserCol();
        columns = gather(columns, col);
        columns = deal(columns);
    }

    printCols(columns);
    printCentreCard(columns);
    return 0;
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

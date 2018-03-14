#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "readmymind.h"

/*
Initialises a card struct by assigning its suit and rank.
*/
struct Card getCard(int suit, int rank) {
    struct Card card;
    card.suit = suit;
    card.rank = rank;

    return card;
}

struct Deck getDeck() {
    struct Deck deck;
    int suit;
    int rank;
    struct Card card;
    Node node = NULL;

    card = getCard(0, 0);
    deck.node = addNode(node, card);

    for (int i = 1; i < DECK_SIZE; i++) {
        suit = (i / SUIT_SIZE);
        rank = (i % SUIT_SIZE);
        card = getCard(suit, rank);
        deck.node = addNode(deck.node, card);
    }

    return deck;
}

/*
Initialises a Columns struct with 21 random and unique cards from the deck of
52 cards.

@deck - deck of cards to use for initialisation.
*/
struct Columns fill(Node deckHead) {
    //Declares Columns struct to be returned with 21 random cards.
    struct Columns columns;
    columns.first = malloc(sizeof(struct LinkedList));
    columns.second = malloc(sizeof(struct LinkedList));
    columns.third = malloc(sizeof(struct LinkedList));

    //Stores number of cards chosen
    int counter = 0;

    //Sets random seed.
    srand(time(NULL));
    int random = 0;

    Node currentNode = NULL;

    // Repeats until 21 - (3 * 7) - unique cards have been assigned to columns
    while (counter < (NUM_COLUMNS * COLUMN_SIZE)) {
        //Generates a random number between 0 and size of the remaining cards in deck
        random = rand()%DECK_SIZE;
        currentNode = getNode(deckHead, random);

        if (currentNode->chosen == true) continue;

        int column = counter / COLUMN_SIZE;

        //TODO Abstract to function.
        if (column == 0) {
            columns.first = addNode(columns.first, currentNode->card);
        } else if (column == 1) {
            columns.second = addNode(columns.second, currentNode->card);
        } else if (column == 2) {
            columns.third = addNode(columns.third, currentNode->card);
        }


        currentNode->chosen = true;
        counter++;
    }

    return columns;
}

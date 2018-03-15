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

/*
Generates a deck struct whose cards are populated with integers representing
the suit (0 - 3) and rank (0 - 12) of the current card.
*/
struct Deck getDeck() {
    struct Deck deck;
    int suit;
    int rank;
    struct Card card;
    Node node = NULL;

    //Sets head of deck to (0,0)
    card = getCard(0, 0);
    deck.node = addNode(node, card);

    //Adds rest of cards to deck
    for (int i = 1; i < DECK_SIZE; i++) {

        //Calculates suit and rank
        suit = (i / SUIT_SIZE);
        rank = (i % SUIT_SIZE);

        //Creates card struct
        card = getCard(suit, rank);

        //Adds card to deck
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

    // Memory allocates three lists for the columns struct
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

        //Sets current node to node in deck list at random index
        currentNode = getNode(deckHead, random);

        //If the current node has already been chosen then go to next iteration
        if (currentNode->chosen == true) continue;

        // Calculate column to store card in
        int column = counter / COLUMN_SIZE;

        //Selects column to add card to and adds currentNode node
        if (column == 0) {
            columns.first = addNode(columns.first, currentNode->card);
        } else if (column == 1) {
            columns.second = addNode(columns.second, currentNode->card);
        } else if (column == 2) {
            columns.third = addNode(columns.third, currentNode->card);
        }

        //Sets chosen to true for currentNode
        currentNode->chosen = true;

        //Increments number of cards chosen
        counter++;
    }

    return columns;
}

#ifndef HEADER
#define HEADER

#include <stdbool.h>

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

// Used for reference https://www.hackerearth.com/practice/data-structures/linked-list/singly-linked-list/tutorial/
// Has a card to store the card value, a next pointer to the next node in the list,
// an index signifying the node's position in the list, and a bool signifying whether
// the card has been chosen to be one of the 21 cards.
struct LinkedList {
    struct Card card;
    struct LinkedList* next;
    int index;
    bool chosen;
};

//Allows declareation of LinkedList structs using Node keyword
typedef struct LinkedList* Node;

//Deck struct is just a linked list.
typedef struct Deck {
    Node node;
}Deck;

//Columns struct is three linked lists.
typedef struct Columns {
    Node first;
    Node second;
    Node third;
}Columns;

// Prompts user to enter the column that their card is in.
int getUserCol();

// Validates the user's input
bool isValidInp(char* input);

// Converts the user's input to an integer
int charToInt(char input);

// Creates and returns a card object given an integer suit and rank
struct Card getCard(int suit, int rank);

// Creates and returns a deck populated with 52 cards
struct Deck getDeck();

// Fills a Columns struct with 21 random unique cards and returns the columns
struct Columns fill(Node deckHead);

// Prints the contents of a columns struct
void printCols(struct Columns columns);

// Prints the centre card of a columns struct
void printCentreCard(struct Columns columns);

/*
'Gathers' the user's columns by placing the selected column in the middle of a
new columns struct
*/
struct Columns gather(struct Columns columns, int col);

/* Deals the cards of a columns struct and returns the new
resulting columns struct */
struct Columns deal(struct Columns columns);

//Memory allocates a new node and sets its initial values.
Node createNode();

//Adds a node to the tail of a list
Node addNode(Node head, struct Card card);

//Gets the node in a list at a given index
Node getNode(Node head, int index);

//Prints a card struct
void printCard(Node node);

//Prints the suit of a card struct
void printSuit(int suit);

//Prints the rank of a card struct.
void printRank(int rank);

//Updates the indices of a list from a given index
void updateIndices(Node node, int index);

void freeList(Node node);

#endif

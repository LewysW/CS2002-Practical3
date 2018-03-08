#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>
#include "cards.h"

int main() {
    int col = getUserCol();
    struct Deck deck = getDeck();
    struct Columns columns = fill(deck);
    printCols(columns);
    return 0;
}

int getUserCol() {
    char input[10];

    do {
        printf("Which column does your card sit in? (L, M, R)\n");
        fgets(input, 10, stdin);
    } while (!isValidInp(input));

    return charToInt(input);
}

int isValidInp(char input[]) {
    char valid[6] = {'l', 'm', 'r', 'L', 'M', 'R'};

    if (strlen(input) > 2) return 0;

    for (int i = 0; i < sizeof(valid)/sizeof(valid[0]); i++) {
        if (input[0] == valid[i]) {
            assert(input != NULL);
            return 1;
        }
    }

    return 0;
}

int charToInt(char input[]) {
    if (input[0] == 'l' || input[0] == 'L') {
        return 0;
    } else if (input[0] == 'm' || input[0] == 'M') {
        return 1;
    } else if (input[0] == 'r' || input[0] == 'R') {
        return 2;
    }

    // Should never happen
    return -1;
}

struct Deck getDeck() {
    struct Deck deck;
    int rank;
    int suit;

    for (int  i = 0; i < deckSize; i++) {
        suit = (i / suitSize) + 1;
        rank = (i % suitSize) + 1;
        deck.cards[i] = getCard(suit, rank);
    }

    return deck;
}

struct Card getCard(int suit, int rank) {
    struct Card card;
    card.suit = suit;
    card.rank = rank;

    return card;
}

struct Columns fill(struct Deck deck) {
    struct Columns columns;
    int chosen[52] = { 0 };
    int counter = 0;
    srand(time(NULL));
    int random = 0;

    // Repeats until 21 unique cards have been assigned to columns
    while (counter < 21) {
        //Generates a random number between
        random = rand()%deckSize;
        if (chosen[random] == 0) {
            /* Counter / columnSize finds the current column,
            counter % columnSize calculates current card in column.
            The random card selected is assigned to the card position in this column */
            columns.column[counter / columnSize].cards[counter % columnSize] = deck.cards[random];
            // Increments number of cards assign to columns
            counter++;
            // Sets card to used so it won't be assigned twice.
            chosen[random] = 1;
        }
    }

    return columns;
}

void printCols(struct Columns columns) {
    for (int i = 0; i < columnSize; i++) {
        for (int j = 0; j < numColumns; j++) {
            printf("(%d, %d) ", columns.column[i].cards[j].suit, columns.column[i].cards[j].rank);
        }

        printf("\n");
    }
}

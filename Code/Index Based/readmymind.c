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
    int col = getUserCol();
    printCols(columns);
    //char * input;
    //input = malloc(2);
    //scanf("%s", input);
    //printCols(columns);

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

bool isValidInp(char input[]) {
    char valid[6] = {'l', 'm', 'r', 'L', 'M', 'R'};

    if (strlen(input) > 2) return false;

    for (int i = 0; i < sizeof(valid)/sizeof(valid[0]); i++) {
        if (input[0] == valid[i]) {
            assert(input != NULL);
            return true;
        }
    }

    return false;
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

    for (int  i = 0; i < DECK_SIZE; i++) {
        suit = (i / SUIT_SIZE);
        rank = (i % SUIT_SIZE);
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
    int chosen[DECK_SIZE] = { 0 };
    int counter = 0;
    srand(time(NULL));
    int random = 0;

    // Repeats until 21 (3 * 7) unique cards have been assigned to columns
    while (counter < (NUM_COLUMNS * COLUMN_SIZE)) {
        //Generates a random number between
        random = rand()%DECK_SIZE;
        if (chosen[random] == 0) {
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

void printCols(struct Columns columns) {
    int suit;
    int rank;

    for (int i = 0; i < COLUMN_SIZE; i++) {
        for (int j = 0; j < NUM_COLUMNS; j++) {
            suit = columns.column[i].cards[j].suit;
            rank = columns.column[i].cards[j].rank;

            //Special formatting for '10' card
            if (RANKS[rank] == "10") printf("%s%s ", RANKS[rank], SUITS[suit]);
            else printf("%s%s  ", RANKS[rank], SUITS[suit]);
        }

        printf("\n");
    }
}

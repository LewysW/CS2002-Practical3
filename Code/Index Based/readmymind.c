#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>
#include "cards.h"

int main() {
    int col = getUserCol();
    struct Deck deck = getDeck();
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

    for (int  i = 0; i < 52; i++) {
        suit = (i / 13) + 1;
        rank = (i % 13) + 1;
        deck.cards[i] = getCard(suit, rank);
    }

    return deck;
}

struct Card getCard(int suitNum, int rank) {
    char suit;

    if (suitNum == 1) {
        suit = 'S';
    } else if (suitNum == 2) {
        suit = 'H';
    } else if (suitNum == 3) {
        suit = 'C';
    } else if (suitNum == 4) {
        suit = 'D';
    }

    struct Card card;
    card.suit = suit;
    card.rank = rank;

    printf("Suit: %c, Rank: %d\n", card.suit, card.rank);
    return card;
}

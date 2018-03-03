#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cards.h"

int main() {
    Deck* deck = make_deck();

    for (int i = 0; i < 52; i++) {
        int cardMem = i * sizeof(Card);
        printf("%c, %c\n", ((Card*) *(deck->cards + cardMem))->suit, ((Card*) *(deck->cards + cardMem))->rank);
    }
    return 0;
}

Card* make_card(char suit, char rank) {
    Card* card = calloc(1, sizeof(Card));
    card->suit = suit;
    card->rank = rank;
    return card;
}

void free_card(Card* card) {
    free(card);
}

Deck* make_deck() {
    Deck* deck = calloc(1, sizeof(Deck));
    deck->cards = calloc(52, sizeof(Card));

    for (int i = 0; i < 52; i++) {
        int cardMem = i * sizeof(Card);
        *(deck->cards + cardMem) = make_card('C', 'K');
        printf("%c, %c\n", ((Card*) *(deck->cards + cardMem))->suit, ((Card*) *(deck->cards + cardMem))->rank);
    }

    return deck;
}

void free_deck(Deck* deck) {
    free(deck);
}

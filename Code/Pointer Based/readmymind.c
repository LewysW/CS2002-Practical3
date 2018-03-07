#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cards.h"

int main() {
    Deck deck = make_deck();
    print_deck(deck);
    return 0;
}

Card make_card(char suit, char rank) {
    Card card;
    card.suit = suit;
    card.rank = rank;
    return card;
}

Deck make_deck() {
    Deck deck;
    deck.cards = calloc(52, sizeof(Card));

    for (int i = 0; i < 52; i++) {
        int cardMem = i * sizeof(Card);
        *(deck.cards + cardMem) = make_card('C', 'K');
        //printf("*(p + %d) : %c, %c\n", cardMem, (deck.cards + cardMem)->suit, (deck.cards + cardMem)->rank);
    }

    return deck;
}

void print_deck(Deck deck) {
    char suits[53];
    char ranks[53];

    for (int i = 0; i < 52; i++) {
        int cardMem = i * sizeof(Card);
        suits[i] = (deck.cards + cardMem)->suit;
        ranks[i] = (deck.cards + cardMem)->rank;
        printf("%c, %c", suits[i], ranks[i]);
    }
    suits[52] = '\0';
    ranks[52] = '\0';

    printf("%s", suits);
    printf("%s", ranks);
}

#ifndef HEADER
#define HEADER
// Struct to represent playing card
// suit - S, C, H, D
// rank - A, 2..10, J, Q, K
typedef struct {
    char suit;
    char rank;
} Card;

typedef struct {
    Card* cards;
} Deck;

Card make_card(char suit, char rank);

Deck make_deck();
void free_deck();

void print_deck(Deck deck);

#endif

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "readmymind.h"

//Used for displaying cards
const char* SUITS[NUM_SUITS] = {"♠", "♥", "♦", "♣"};
const char* RANKS[SUIT_SIZE] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

/**
Prompts the user to enter a letter corresponding to the column that their card
resides in.
*/
int getUserCol() {
    //Stores the users input
    char* input = malloc(sizeof(100));

    do {
        printf("Which column does your card sit in? (L, M, R)\n");

        //Told to avoid scanf where possible but no buffer issues have arisen during testing
        scanf("%s", input);

        //Repeats while the input is invalid.
    } while (!isValidInp(input));

    // Returns an integer from 0 to 2 corresponding to the character chosen by the user.
    int charInt = charToInt(*(input));
    free(input);
    return charInt;
}

/*
Iterates over the character(s) input by the user and returns a boolean signifying
whether the user's input is valid.

@input - array of characters entered by user.
*/
bool isValidInp(char* input) {
    // Valid characters.
    const char valid[6] = {'l', 'm', 'r', 'L', 'M', 'R'};

    // If the user's input is greater than 1 then return false
    if (strlen(input) > 1) return false;

    /*
    Iterates over the list of valid characters and checks each against the character
    input by the user to see if the input is valid.

    Used size_t to make i and unsigned int to avoid a comparison between a signed and unsigned int
    */
    for (size_t i = 0; i < sizeof(valid)/sizeof(valid[0]); i++) {
        if (*input == valid[i]) {
            assert(input != NULL);
            return true;
        }
    }

    return false;
}

/*
Converts the user's column character into a corresponding int value to be easier
to iterate over in the program.
*/
int charToInt(char input) {
    //l/L corresponds to 0
    if (input == 'l' || input == 'L') {
        return 0;
    //m/M corresponds to 1
    } else if (input == 'm' || input == 'M') {
        return 1;
    //r/R corresponds to 2
    } else if (input == 'r' || input == 'R') {
        return 2;
    }

    // Should never happen but will terminate program if it does.
    assert(!"Uncreachable Code");
}


/*
Iterates over a Columns struct and prints outs the cards in each column.

@Columns to be printed
*/
void printCols(struct Columns columns) {
    int suit;
    int rank;

    //Iterates over column size in outer loop and number of columns in inner loop
    //so that cards are printed in the same order as they would be dealt in real life.
    for (int i = 0; i < COLUMN_SIZE; i++) {
        for (int j = 0; j < NUM_COLUMNS; j++) {

            //Gets the suit and rank at the
            suit = columns.column[j].cards[i].suit;
            rank = columns.column[j].cards[i].rank;

            prettyPrint(suit, rank);

        }

        printf("\n");
    }
}

/*
Prints the card in the centre of the columns.

@columns - of which to print the centre card.
*/
void printCentreCard(struct Columns columns) {
    int suit = columns.column[NUM_COLUMNS / 2].cards[COLUMN_SIZE / 2].suit;
    int rank = columns.column[NUM_COLUMNS / 2].cards[COLUMN_SIZE / 2].rank;
    printf("Your card is the %s%s\n", RANKS[rank], SUITS[suit]);
}

void prettyPrint(int suit, int rank) {

    switch(suit) {
        case 1:
        case 2:
            if (rank == 9) printf("%s"ANSI_RED"%s "ANSI_ESCAPE, RANKS[rank], SUITS[suit]);
            else printf("%s"ANSI_RED"%s  "ANSI_ESCAPE, RANKS[rank], SUITS[suit]);
            break;
        default:
            if (rank == 9) printf("%s%s ", RANKS[rank], SUITS[suit]);
            else printf("%s%s  ", RANKS[rank], SUITS[suit]);
            break;
    }
}

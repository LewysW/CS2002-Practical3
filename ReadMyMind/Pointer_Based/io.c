#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "readmymind.h"

/**
Prompts the user to enter a letter corresponding to the column that their card
resides in.
*/
int getUserCol() {
    //Stores the users input
    char* input;


    do {
        printf("Which column does your card sit in? (L, M, R)\n");
        fgets(input, 10, stdin);

        //Repeats while the input is invalid.
    } while (!isValidInp(input));

    // Returns an integer from 0 to 2 corresponding to the character chosen by the user.
    return charToInt(*(input));
}

/*
Iterates over the character(s) input by the user and returns a boolean signifying
whether the user's input is valid.

@input - array of characters entered by user.
*/
bool isValidInp(char* input) {
    if (strlen(input) > 2) return false;

    switch(*(input)) {
        case 'l':
        case 'L':
        case 'r':
        case 'R':
        case 'm':
        case 'M':
            return true;
            break;
        default:
            return false;
            break;
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
    //Iterates over column size in outer loop and number of columns in inner loop
    //so that cards are printed in the same order as they would be dealt in real life.
    for (int i = 1; i <= COLUMN_SIZE; i++) {
        printCard(getNode(columns.first, i));
        printCard(getNode(columns.second, i));
        printCard(getNode(columns.third, i));
        printf("\n");


    }
}

void printCard(Node node) {
    struct Card card = node->card;
    int suit = card.suit;
    int rank = card.rank;

    printRank(rank);
    printSuit(suit);

    if (rank != 9) printf(" ");
}

void printSuit(int suit) {
    switch(suit) {
        case 0:
            printf("♠");
            break;
        case 1:
            printf("♥");
            break;
        case 2:
            printf("♦");
            break;
        case 3:
            printf("♣");
            break;
    }

    printf(" ");
}

void printRank(int rank) {
    switch(rank) {
        case 0:
            printf("A");
            break;
        case 10:
            printf("J");
            break;
        case 11:
            printf("Q");
            break;
        case 12:
            printf("K");
            break;
        default:
            printf("%d", rank + 1);
            break;
    }
}

/*
Prints the card in the centre of the columns.

@columns - of which to print the centre card.
*/
void printCentreCard(struct Columns columns) {
    Node node = getNode(columns.second, (COLUMN_SIZE / 2) + 1);
    printf("Your card is: ");
    printCard(node);
}

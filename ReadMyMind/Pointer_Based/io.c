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
    char* input = malloc(sizeof(100));


    do {
        printf("Which column does your card sit in? (L, M, R)\n");
        scanf("%s", input);

        //Repeats while the input is invalid.
    } while (!isValidInp(input));

    // Returns an integer from 0 to 2 corresponding to the character chosen by the user.
    return charToInt(*(input));
}

/*
Uses a switch statement to determine whether the user's input is valid. If the
character entered is a valid case then true is returned otherwise by default
false is returned.

@input - array of characters entered by user.
*/
bool isValidInp(char* input) {
    // If the user's input is greater than 1 then return false
    if (strlen(input) > 1) return false;

    // Cases with valid input return true otherwise false is returned.
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

    // Should never happen but will terminate program if it does.
    assert(!"Uncreachable Code");
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
Iterates over each of the column lists in the columns struct and prints the cardsDealt
of each

@Columns to be printed
*/
void printCols(struct Columns columns) {
    // Prints card at current row (i) of each column list.
    for (int i = 1; i <= COLUMN_SIZE; i++) {
        printCard(getNode(columns.first, i));
        printCard(getNode(columns.second, i));
        printCard(getNode(columns.third, i));
        printf("\n");

    }
}

/*
Prints the card value of the node passed in.

@node - element of card to be printed.
*/
void printCard(Node node) {
    //Gets the card at the node.
    struct Card card = node->card;

    //Gets suit and rank of card.
    int suit = card.suit;
    int rank = card.rank;

    //Prints rank and suit.
    printRank(rank);
    printSuit(suit);

    //Adds space if card is double digit character (10)
    if (rank != 9) printf(" ");
}

/*
Prints the icon corresponding to the suit integer passed in.

@ suit - integer corresponding to suit to be printed.
*/
void printSuit(int suit) {
    /*
    Prints a suit icon corresponding to an integer from 0 - 3.
    Used switch statement to avoid declaring an array of icons.
    */
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

/*
Prints the character(s) corresponding to the rank integer passed in.

@ rank - integer corresponding to suit to be printed.
*/
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
            //If the rank is not an alphabetic character then print the rank integer + 1
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
    printf("\n");
}

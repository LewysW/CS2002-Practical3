#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "readmymind.h"

/*
Performs the gather stage of the trick by creating a new set of columns with the
column chosen by the user placed in the centre.
*/
struct Columns gather(struct Columns columns, int col) {
    struct Columns newColumns;

    /*
    For each case, assigns the chosen column (at col) to the centre column of
    the newColumns struct. Then assigns the remaining nodes of columns to the edge
    columns of newColumns.

    Implemented using a switch statement to avoid using arrays as in the index
    based version.
    */
    switch(col) {
        case 0:
            newColumns.second = columns.first;
            newColumns.first = columns.second;
            newColumns.third = columns.third;
            break;
        case 1:
            newColumns.second = columns.second;
            newColumns.first = columns.first;
            newColumns.third = columns.third;
            break;
        case 2:
            newColumns.second = columns.third;
            newColumns.first = columns.second;
            newColumns.third = columns.first;
            break;
    }

    return newColumns;

}


/*
Concatenates three linked lists of Columns struct and deals cards (from left to right)
to a new Columns struct until 21 cards have been dealt.

@columns - column linked lists containing cards to be dealt into 3 new columns.
*/
struct Columns deal(struct Columns columns) {
    //New Columns
    struct Columns newColumns;

    //Joins second and third column linked lists together, throwing away the head of the third
    getNode(columns.second, COLUMN_SIZE)->next = getNode(columns.third, 1);

    //Joins second and third column linked lists together, throwing away the head of the second
    getNode(columns.first, COLUMN_SIZE)->next = getNode(columns.second, 1);

    //Stores the concatenated linked list in catColumn, throwing away the head.
    Node catColumn = getNode(columns.first, 1);

    //Updates the indices of the list so that they become 0 - 20.
    updateIndices(catColumn, 0);

    //Allocates space for new columns.
    newColumns.first = malloc(sizeof(struct LinkedList));
    newColumns.second = malloc(sizeof(struct LinkedList));
    newColumns.third = malloc(sizeof(struct LinkedList));

    //Initialises number of cards dealt to 0.
    int cardsDealt = 0;

    //Iterates until number of cards dealt is equal to the number of elements in a Columns struct
    while (cardsDealt < (NUM_COLUMNS * COLUMN_SIZE)) {

        //Iterates over each column to be dealt a card.
        for (int j = 0; j < NUM_COLUMNS; j++) {

            //Decides on which column to deal a card to based on the value of j
            switch(j) {
                /*
                Adds a card to the selected column from the concatenated column
                at the index value of cardDealt. Then increments the number of
                cards dealt.
                */
                case 0:
                    addNode(newColumns.first, getNode(catColumn, cardsDealt)->card);
                    cardsDealt++;
                    break;
                case 1:
                    addNode(newColumns.second, getNode(catColumn, cardsDealt)->card);
                    cardsDealt++;
                    break;
                case 2:
                    addNode(newColumns.third, getNode(catColumn, cardsDealt)->card);
                    cardsDealt++;
                    break;
            }
        }
    }

    return newColumns;

}

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
Deals the cards into 3 new columns horizontally from left to right.

@columns - columns containing cards to be dealt into 3 new columns.
*/
struct Columns deal(struct Columns columns) {
    //New Columns
    struct Columns newColumns;
    getNode(columns.second, COLUMN_SIZE)->next = getNode(columns.third, 1);
    getNode(columns.first, COLUMN_SIZE)->next = getNode(columns.second, 1);

    Node catColumn = getNode(columns.first, 1);
    updateIndices(catColumn, 0);

    newColumns.first = malloc(sizeof(struct LinkedList));
    newColumns.second = malloc(sizeof(struct LinkedList));
    newColumns.third = malloc(sizeof(struct LinkedList));
    int cardsDealt = 0;

    while (cardsDealt < (NUM_COLUMNS * COLUMN_SIZE)) {
        for (int j = 0; j < NUM_COLUMNS; j++) {
            switch(j) {
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

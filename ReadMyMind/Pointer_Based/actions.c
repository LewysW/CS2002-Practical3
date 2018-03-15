#include <stdbool.h>
#include <stdlib.h>
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

    printList(catColumn);

    for (int i = 1; i <= (NUM_COLUMNS * COLUMN_SIZE); i++) {
        for (int j = 0; i < NUM_COLUMNS; j++) {
            switch(i) {
                case 0:
                    newColumns.first = addNode(newColumns.first, getNode(catColumn, i)->card);
                    break;
                case 1:
                    newColumns.second = addNode(newColumns.second, getNode(catColumn, i)->card);
                    break;
                case 2:
                    newColumns.third = addNode(newColumns.third, getNode(catColumn, i)->card);
                    break;
            }
        }
    }

    return newColumns;

}

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "readmymind.h"

int main() {
    /*Declares a deck of 52 cards, the columns to store the 21 cards and an int
    to store the user's choice of column. */
    struct Deck deck = getDeck();
    printList(deck.node);
    //removeNode(deck.node, 10);
    //printList(deck.node);
    struct Columns columns = fill(deck.node);
    printList(columns.first);
    printList(columns.second);
    printList(columns.third);

    //int col;

    /* Repeats 3 times, each time printing the 3 columns of 7 cards and prompting
     the user to enter their column of choice signifying where their card is.
     Cards are gathered and re-dealt into new columns before being printed */
    //for (int i = 0; i < 3; i++) {
        //printCols(columns);
        //col = getUserCol();
        //columns = gather(columns, col);
        //columns = deal(columns);
    //}

    //printCols(columns);
    //printCentreCard(columns);
    return 0;
}

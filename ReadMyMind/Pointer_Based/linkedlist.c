#include "readmymind.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// Used for reference https://www.hackerearth.com/practice/data-structures/linked-list/singly-linked-list/tutorial/

//Creates a new node
Node createNode() {
    Node newNode;
    //Allocates memory for node
    newNode = malloc(sizeof(struct LinkedList));

    //Sets attribute values of next to NULL, index to 0, and chosen to false.
    //Chosen is used when cards are randomly selected for the initial columns.
    newNode->next = NULL;
    newNode->index = 0;
    newNode->chosen = false;
    return newNode;
}


Node addNode(Node head, struct Card card) {
    Node newNode;
    Node tail;
    newNode = createNode();
    newNode->card = card;

    if (head == NULL) {
        head = newNode;
    } else {
        tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }

        tail->next = newNode;
        newNode->index = (tail->index) + 1;
    }

    return head;
}

//Recursively goes through a linked list and returns the node at a given index
Node getNode(Node head, int index) {
    if (head->index == index) return head;

    return getNode(head->next, index);
}

/*
Takes an index and sets the index of the initial node to that index and recursively
sets every subsequent node index to that index + 1 */
void updateIndices(Node node, int index) {
    if (node != NULL) {
        node->index = index;
        updateIndices(node->next, index + 1);
   }
}

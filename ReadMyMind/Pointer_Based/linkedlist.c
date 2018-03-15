#include "readmymind.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/*
Used this source - https://www.hackerearth.com/practice/data-structures/linked-list/singly-linked-list/tutorial/ -
to help implement struct, addNode and createNode
*/

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


//Adds a node to the end of a linked list
Node addNode(Node head, struct Card card) {
    Node newNode;
    Node tail;

    //Creates the node by allocating space and setting initial values.
    newNode = createNode();

    //Sets card attribute to given card.
    newNode->card = card;

    //If the head of the list is null (so list is empty) then set head to newNode
    if (head == NULL) {
        head = newNode;

    //Otherwise set head to tail
    } else {
        tail = head;

        //And keep updating tail to next element until the end of the list is reached
        while (tail->next != NULL) {
            tail = tail->next;
        }

        /*
        Finally at end of list, set tail->next to newNode and set the index of
        the newNode to 1 greater than the index of tail
        */
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

//Recursively frees linked list
void freeList(Node node) {
    Node newNode = node->next;
    free(node);
    if (newNode != NULL) freeList(newNode);
}

#include "readmymind.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// Used for reference https://www.hackerearth.com/practice/data-structures/linked-list/singly-linked-list/tutorial/
Node createNode() {
    Node newNode;
    newNode = malloc(sizeof(struct LinkedList));
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

Node getNode(Node head, int index) {
    if (head->index == index) return head;

    return getNode(head->next, index);
}

void updateIndices(Node node, int index) {
    if (node != NULL) {
        node->index = index;
        updateIndices(node->next, index + 1);
   }
}

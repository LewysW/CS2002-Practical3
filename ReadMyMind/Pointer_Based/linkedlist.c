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

//TODO Use to display cards at end
void printNode(Node head, int index) {
    if (head != NULL && head->index != index) {
        Node nextNode = head->next;
        printf("Suit: %d, Rank: %d\n", head->card.suit, head->card.rank);
        printNode(nextNode, index);
    }
}

void printList(Node head) {
    if (head != NULL) {
        printf("Suit: %d, Rank: %d\n", head->card.suit, head->card.rank);
        printList(head->next);
    }
}

Node getNode(Node head, int index) {
    if (head->index == index) return head;

    return getNode(head->next, index);
}

#ifndef LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode ListNode;
typedef struct LinkedList LinkedList;

// CREATE FUNCTIONS

ListNode *createNode(int n);
LinkedList *createList();

// INSERT FUNCTIONS

void insertAtInit(LinkedList *linkedList, int n);
void insertAtEnd(LinkedList *linkedList, int n);

// REMOVE FUNCTION

void removeNodeList(LinkedList *linkedList, int n);

// SEARCH FUNCTION

ListNode *searchNode(LinkedList *linkedList, int n);

// FREE FUNCTION

void freeLinkedList(LinkedList *linkedList);


#endif
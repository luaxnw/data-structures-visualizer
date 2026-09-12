#ifndef LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode ListNode;
typedef struct LinkedList LinkedList;


// CREATE FUNCTIONS

ListNode *createNode(int n);
LinkedList *createList();
void initList(void);

// INSERT FUNCTIONS

void insertAtInit(int n);
void insertAtEnd(int n);

// REMOVE FUNCTION

void removeNodeList(int n);

// SEARCH FUNCTION

ListNode *searchNode(int n);

// FREE FUNCTION

void freeLinkedList();

// PRINT FUNCTION

void printLinkedList();

// LINKED LIST T0 JSON FUNCTION

char *linkedListToJson();

int saveJSON(const char *archive);



#endif
#include "linked_list.h"


struct ListNode
{
    int n;
    ListNode *next;
};

struct LinkedList
{
    ListNode *head;
    ListNode *tail;
};

// CREATE FUNCTIONS

ListNode *createNode(int n){

    ListNode *new = malloc(sizeof(ListNode));

    if (new == NULL)
        return NULL;

    new->next = NULL;
    new->n = n;

    return new;

}

LinkedList *createList(){

    LinkedList *newList = malloc(sizeof(LinkedList));

    if (newList == NULL)
        return NULL;

    newList->head = NULL;
    newList->tail = NULL;

    return newList;
}

// INSERT FUNCTIONS

void insertAtInit(LinkedList *linkedList, int n);
void insertAtEnd(LinkedList *linkedList, int n);

// REMOVE FUNCTION

void removeNodeList(LinkedList *linkedList, int n);

// SEARCH FUNCTION

ListNode *searchNode(LinkedList *linkedList, int n);

// FREE FUNCTION

void freeLinkedList(LinkedList *linkedList);

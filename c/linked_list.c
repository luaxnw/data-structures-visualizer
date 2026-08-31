#include "linked_list.h"

struct ListNode
{
    int n;
    ListNode *next;
    ListNode *prev;
};

struct LinkedList
{
    ListNode *head;
    ListNode *tail;
};

// CREATE FUNCTIONS

ListNode *createNode(int n)
{

    ListNode *new = malloc(sizeof(ListNode));

    if (new == NULL)
        return NULL;

    new->next = NULL;
    new->prev = NULL;
    new->n = n;

    return new;
}

LinkedList *createList()
{

    LinkedList *newList = malloc(sizeof(LinkedList));

    if (newList == NULL)
        return NULL;

    newList->head = NULL;
    newList->tail = NULL;

    return newList;
}

// INSERT FUNCTIONS

void insertAtInit(LinkedList *linkedList, int n)
{
    ListNode *new = createNode(n);
    if (new == NULL)
        return NULL;

    if (linkedList->head == NULL)
    {
        linkedList->head = new;
        linkedList->tail = new;
        return;
    }

    new->next = linkedList->head;
    linkedList->head->prev = new;
    linkedList->head = new;
}

void insertAtEnd(LinkedList *linkedList, int n)
{
    ListNode *new = createNode(n);
    if (new == NULL)
        return NULL;

    if (linkedList->head == NULL)
    {
        linkedList->head = new;
        linkedList->tail = new;
        return;
    }

    new->prev = linkedList->tail;
    linkedList->tail->next = new;
    linkedList->tail = new;
}

// REMOVE FUNCTION

void removeNodeList(LinkedList *linkedList, int n)
{
    ListNode *aux = linkedList->head;
    ListNode *prev = NULL;

    while (aux != NULL)
    {
        if (aux->n == n)
        {
            if (prev == NULL)
            {
                linkedList->head = aux->next;
            }
            else
            {
                prev->next = aux->next;
            }

            free(aux);
            return;
        }

        prev = aux;
        aux = aux->next;
    }

    printf("Node not found\n");
}

// SEARCH FUNCTION

ListNode *searchNode(LinkedList *linkedList, int n)
{
    ListNode *aux = NULL;

    for (aux = linkedList->head; aux != NULL; aux = aux->next)
    {
        if (aux->n == n)
            return aux;
    }

    printf("Node not found\n");
    return NULL;
}

// FREE FUNCTION

void freeLinkedList(LinkedList *linkedList)
{
    ListNode *aux = NULL;

    while (linkedList->head != NULL)
    {
        aux = linkedList->head;
        linkedList->head = aux->next;
        free(aux);
    }

    free(linkedList);
}

// PRINT FUNCTION

void printLinkedList(LinkedList *linkedList)
{
    ListNode *aux = NULL;

    for (aux = linkedList->head; aux != NULL; aux = aux->next)
    {
        printf("%d->", aux->n);
    }
    printf("\n");
}

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

char *linkedListToJson(const LinkedList *list)
{
    size_t capacity = 128;
    size_t length = 0;

    char *json = malloc(capacity);

    if (json == NULL)
        return NULL;

    length += snprintf(
        json + length,
        capacity - length,
        "{\"type\":\"linked_list\",\"values\":[");

    ListNode *current = list->head;

    while (current != NULL)
    {
        char buffer[32];

        int written = snprintf(
            buffer,
            sizeof(buffer),
            "%d",
            current->n);

        if (length + written + 3 >= capacity)
        {
            capacity *= 2;

            char *new_json = realloc(json, capacity);

            if (new_json == NULL)
            {
                free(json);
                return NULL;
            }

            json = new_json;
        }

        if (current != list->head)
        {
            json[length++] = ',';
        }

        for (int i = 0; i < written; i++)
        {
            json[length++] = buffer[i];
        }

        current = current->next;
    }

    if (length + 3 >= capacity)
    {
        capacity += 3;

        char *new_json = realloc(json, capacity);

        if (new_json == NULL)
        {
            free(json);
            return NULL;
        }

        json = new_json;
    }

    json[length++] = ']';
    json[length++] = '}';
    json[length] = '\0';

    return json;
}

int saveJSON(const char *archive, const LinkedList *linkedList)
{
    if (archive == NULL || linkedList == NULL)
    {
        return 0;
    }

    char *jsonContent = linkedListToJson(linkedList);
    if (jsonContent == NULL)
    {
        return 0;
    }

    FILE *arq = fopen(archive, "w");
    if (arq == NULL)
    {
        free(jsonContent);
        return 0;
    }

    fprintf(arq, "%s\n", jsonContent);

    fclose(arq);
    free(jsonContent);

    return 1;
}
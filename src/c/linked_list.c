#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

static LinkedList *linkedList = NULL;

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

void initList(void)
{
    linkedList = createList();
}

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

void insertAtInit(int n)
{
    ListNode *new = createNode(n);
    if (new == NULL)
        return;

    if (linkedList->head == NULL)
    {
        linkedList->head = new;
        linkedList->tail = new;
        saveJSON("/c/data/list.json");

        return;
    }

    new->next = linkedList->head;
    linkedList->head->prev = new;
    linkedList->head = new;
    saveJSON("/c/data/list.json");
}

void insertAtEnd(int n)
{
    ListNode *new = createNode(n);
    if (new == NULL)
        return;

    if (linkedList->head == NULL)
    {
        linkedList->head = new;
        linkedList->tail = new;
        saveJSON("data/list.json");
        return;
    }

    new->prev = linkedList->tail;
    linkedList->tail->next = new;
    linkedList->tail = new;
    saveJSON("data/list.json");
}

// REMOVE FUNCTION

void removeNodeList(int n)
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
            saveJSON("data/list.json");

            return;
        }

        prev = aux;
        aux = aux->next;
    }

    printf("Node not found\n");
}

// SEARCH FUNCTION

ListNode *searchNode(int n)
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

void freeLinkedList()
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

void printLinkedList()
{
    ListNode *aux = NULL;

    for (aux = linkedList->head; aux != NULL; aux = aux->next)
    {
        printf("%d->", aux->n);
    }
    printf("\n");
}

char *linkedListToJson()
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

    ListNode *current = linkedList->head;

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

        if (current != linkedList->head)
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

int saveJSON(const char *archive)
{
    if (archive == NULL || linkedList == NULL)
    {
        return 0;
    }

    char *jsonContent = linkedListToJson();
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

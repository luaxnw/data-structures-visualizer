#include "../include/linked_list.h"

int main()
{

    initList();
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtInit(0);
    removeNodeList(3);
    

    printLinkedList();
    freeLinkedList();

    // saveJSON("list_event.json");

    return 0;
}
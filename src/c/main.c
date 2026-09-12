#include "linked_list.h"

int main()
{

    initList();
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtInit(-11);
    removeNodeList(2);

    printLinkedList();


    // saveJSON("list_event.json");

    return 0;
}
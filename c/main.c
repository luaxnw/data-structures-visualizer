#include "linked_list.h"

int main()
{

    LinkedList *list = createList();
    insertAtInit(list, 2);
    insertAtInit(list, 4);
    insertAtInit(list, 5);
    insertAtInit(list, 10);
    insertAtInit(list, 1);
    insertAtEnd(list, 99);
    insertAtEnd(list, 1009);
    insertAtInit(list, -23);

    removeNodeList(list, 2);
    removeNodeList(list, 1009);
    removeNodeList(list, 10);


    saveJSON("list_event.json",list);

    return 0;
}
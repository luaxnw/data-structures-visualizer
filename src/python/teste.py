from ctypes import CDLL

lib = CDLL("../c/lib_linked_list.so")

lib.initList()
lib.insertAtEnd(1)
lib.insertAtEnd(123)
lib.insertAtEnd(0)
lib.insertAtEnd(12)
lib.insertAtEnd(3)
lib.insertAtEnd(5)
lib.removeNodeList(123)

lib.printLinkedList()
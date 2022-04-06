#include "IntList.h"

IntList::IntList() {
    dummyHead = new IntNode(0);
    dummyTail = new IntNode(0);

    dummyHead->prev = nullptr;
    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;
    dummyTail->next = nullptr;
}

IntList::~IntList() {
    
    while (dummyHead != nullptr) {
        IntNode* temp;
        temp = dummyHead;
        dummyHead = dummyHead->next;
        delete temp;
    }
}


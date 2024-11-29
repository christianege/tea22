#include <fmt/chrono.h>
#include <fmt/format.h>
#include "linkedlist.h"


auto main(int argc, char** argv) -> int
{
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", argv[0]);

    List_t* pList = NewList();
    ListNode_t* pNode = NULL;
    for(int i=0; i<5; i++) {
        pNode = NewListNode();
        pNode->data = i;
        InsertIntoLinkedList(pList,pNode);
    }

    ListNode_t* pElem = NewListNode();
    pElem->data = 42;
    pNode = pList->pHead; // Insert into at the head
    InsertIntoLinkedListAfterNode(pList,pNode,pElem);
    
    ListNode_t* pElem2 = NewListNode();
    pElem2->data = 99;
    pNode = pList->pTail; // Insert into at the tail
    InsertIntoLinkedListAfterNode(pList,pNode,pElem2);
    
    RemoveFromList(pList,pElem);
    RemoveFromList(pList,pList->pHead);
    RemoveFromList(pList,pList->pTail);
    
    FreeList(pList);
    return 0; /* exit gracefully*/
}

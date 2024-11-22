#include "linkedlist.h"
#include <stdlib.h> // needed for malloc/free

ListNode_t* NewListNode(void) {
    ListNode_t* pTemp = (ListNode_t*) malloc(sizeof(ListNode_t));
    if(pTemp != NULL) {
        pTemp->pNext = NULL;
        pTemp->data = 0;
    }
    return pTemp;

}
void FreeListNode(ListNode_t* elem) {
    if(elem != NULL) {
        free(elem);
    }
}

List_t* NewList(void) {
    List_t* pTempList = (List_t*) malloc(sizeof(List_t));
    if(pTempList != NULL) {
        pTempList->pHead = NULL;
        pTempList->pTail = NULL;
        pTempList->size = 0;
    }
    return pTempList;
}

void FreeList(List_t* list)  {
    if(list != NULL) {
        // Walk through the list and delete each element
        ListNode_t *pNode = NULL;
        do{
            pNode = GetNext(list,list->pHead);
            FreeListNode(list->pHead);
            list->pHead = pNode;
            if(list->size >= 1) {
                list->size -= 1;
            }  
        }while(pNode != NULL); 
        list->pTail = NULL;
        list->pHead = NULL;


        // free the remaining part
        free(list);
    }
}

int InsertIntoLinkedList(List_t* list, ListNode_t* elem) {
    if(list == NULL || elem == NULL ) {
        return -1;
    }
    elem->pNext = NULL;
    if(list->size == 0) {
        list->pHead = elem;
        list->pTail = elem;
        list->size = 1;
    } else {
        if(list->pTail == NULL) {
            return -2;
        }
        list->pTail->pNext = elem;
        list->size += 1;
        list->pTail = elem;
    }

    return 0;
}

int InsertIntoLinkedListAfterNode(List_t* list, ListNode_t* node /* the node we insert the element into */,
                                  ListNode_t* elem /* the node to be inserted */)
{
    if (list != NULL && node != NULL && elem != NULL)
    {
        list->size += 1;
        ListNode_t* pTemp = node;
        elem->pNext = node->pNext;
        node->pNext = elem;
        if(node == list->pTail) {
            list->pTail = elem;
        }
    return 0;
}
    return -1;
}

int RemoveFromList(List_t* list, ListNode_t* elem) {
    // insert your Code here....
    return 0;
}
ListNode_t* GetNext(const List_t* list, ListNode_t* elem) {
    if((list != NULL) && (elem != NULL) )
    {
        return elem->pNext;
    }
    return NULL;
}
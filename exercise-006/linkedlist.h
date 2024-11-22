#ifndef MY_FANCY_LINKED_LIST_H__
#define MY_FANCY_LINKED_LIST_H__

typedef struct ListNode {
    unsigned int data;
    struct ListNode* pNext;
} ListNode_t;

typedef struct List {
    ListNode_t* pHead;
    ListNode_t* pTail;
    unsigned int size;
} List_t;



#endif
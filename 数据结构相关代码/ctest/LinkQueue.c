#include <stdio.h>
#include <stdlib.h>

typedef int elemType;

typedef struct LinkQueueNode
{
    elemType data;
    struct LinkQueueNode *next;
} LinkQueueNode, *LinkQueue;

int InitLinkQueue(LinkQueue *Q)
{
    *Q = (LinkQueue)malloc(sizeof(LinkQueueNode));
    if (*Q == NULL)
        return 0;
    (*Q)->next = (*Q);
    return 1;
}

int EnterLinkQueue(LinkQueue *Q, elemType x)
{
    LinkQueueNode *temp = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if (temp == NULL)
        return 0;
    temp->data = x;
    temp->next = (*Q)->next;
    (*Q)->next = temp;
    *Q = temp;
    return 1;
}

int DeleteLinkQueue(LinkQueue *Q, elemType *x)
{
    if ((*Q)->next == (*Q))
        return 0;
    LinkQueueNode *temp = (*Q)->next->next;
    (*Q)->next->next = temp->next;
    *x = temp->data;
    if (temp == *Q)
        *Q = (*Q)->next;
    free(temp);
    return 1;
}
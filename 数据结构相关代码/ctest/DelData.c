#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node, *LinkList;

void DelData(LinkList L, ElemType mink, ElemType maxk)
{
    Node *p = L->next, *pre = L;
    while (p && p->data <= mink)
    {
        pre = p;
        p = p->next;
    }
    while (p && p->data < maxk)
    {
        pre->next = p->next;
        free(p);
        p = pre->next;
    }
}
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node, *LinkList;

void delSame(LinkList L)
{
    int hash[5001] = {0};
    Node *p = L->next, *pre = L;
    while (p)
    {
        int k = abs(p->data);
        if (hash[k] == 0)
            hash[k] = 1;
        else
        {
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
    }
}

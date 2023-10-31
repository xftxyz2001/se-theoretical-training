#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node, *LinkList;


void insertNode(Node *p, Node *s) {
    s->next = p->next;
    p->next = s;
    ElemType tmp = p->data;
    p->data = s->data;
    s->data = tmp;
}

void deleteNode(Node *p) {
    Node *q = p->next;
    p->next = q->next;
    p->data = q->data;
    free(q);
}

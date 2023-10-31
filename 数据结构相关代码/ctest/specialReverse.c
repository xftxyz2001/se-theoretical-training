#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node, *LinkList;

void specialReverse(LinkList L)
{
    if (L == NULL || L->next == NULL)
        return;
    // 获取中间节点
    Node *mid = L, *fast = L;
    while (fast && fast->next)
    {
        mid = mid->next;
        fast = fast->next->next;
    }
    Node *p = mid->next;

    while (p) // 头插法，就地逆置链表后半段
    {
        Node *tmp = p->next;
        p->next = mid->next;
        mid->next = p;
        p = tmp;
    }
    p = p->next;         // p在前半段，在p节点后面插入
    Node *q = mid->next; // q指向后半段待被移走的节点
    mid->next = NULL;    // 前后链表断开，设置链表尾
    while (q)
    {
        Node *tmp = q->next;
        q->next = p->next;
        p->next = q;
        q = tmp;
        p = p->next->next;
    }
}
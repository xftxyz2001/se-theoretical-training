/**
 * L是一个带头结点的单链表头指针，在不改变链表元素位置的前提下，设计一个尽可能有效的算法，查找倒数第k个位置上的结点，并分析你所设计算法的时空复杂度。
 */

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node, *LinkList;

Node *findLastk(LinkList L, int k)
{
    if (k < 1 || L == NULL)
    {
        return NULL;
    }

    Node *slow = L, *fast = L;
    while (k--)
    {
        fast = fast->next;
    }
    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

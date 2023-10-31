#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node, *LinkList;

// 判断链表类型（单链表/循环链表） 双指针
int isLoopList(LinkList L)
{
    LinkList slow = L, fast = L;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return 1;
    }
    return 0;
}

// 查找倒数第k个节点 双指针
Node *findKthNode(LinkList L, int k)
{
    LinkList slow = L, fast = L;
    while (k--)
        fast = fast->next;
    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node, *LinkList;

void InsertSort(LinkList L)
{
    if (L == NULL || L->next == NULL)
    {
        return NULL;
    }
    Node *p = L->next->next;
    L->next->next = NULL;
    while (p)
    {
        Node *pre = L;
        // 寻找插入位置
        while (pre->next)
        {
            if (pre->next->data < p->data)
            {
                pre = pre->next;
            }
            else
            {
                break;
            }
        }
        // 插入
        Node *tmp = p->next;
        p->next = pre->next;
        pre->next = p;
        p = tmp;
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}

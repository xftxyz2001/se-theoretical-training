#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node, *LinkList;

Node *findFirstCommonNode(LinkList head1, LinkList head2)
{
    if (!head1 || !head2)
        return NULL;
    Node *p1 = head1, *p2 = head2;
    while (p1 != p2)
    {
        p1 = p1 ? p1->next : head2;
        p2 = p2 ? p2->next : head1;
    }
    // 如果没有相交点，p1 和 p2 最后都会指向 NULL
    return p1;
}

LinkList createList(LinkList l)
{
    Node *head = (Node *)malloc(sizeof(Node));
    Node *p = head;
    for (int i = 0; i < 10; i++)
    {
        Node *n = (Node *)malloc(sizeof(Node));
        n->data = rand() % 100;
        n->next = NULL;
        p->next = n;
        p = n;
    }
    p->next = l ? l->next : NULL;
    return head;
}

void printList(LinkList l)
{
    Node *p = l;
    while (p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    srand((unsigned int)time(NULL));
    LinkList l1 = createList(NULL);
    LinkList l2 = createList(l1);
    LinkList l3 = createList(l1);
    printList(l2);
    printList(l3);
    Node *cn = findFirstCommonNode(l2, l3);
    printf("%d\n", cn ? cn->data : -1);
    return 0;
}

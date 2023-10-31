#include <stdio.h>
#include <stdlib.h>

// 先序遍历先序线索化二叉树
void PreThread(BiThrTree p)
{
    if (p != NULL)
    {
        if (p->lchild == NULL)
        {
            p->LTag = Thread;
            p->lchild = pre;
        }
        if (pre != NULL && pre->rchild == NULL)
        {
            pre->RTag = Thread;
            pre->rchild = p;
        }
        pre = p;
        if (p->LTag == Link)
            PreThread(p->lchild);
        if (p->RTag == Link)
            PreThread(p->rchild);
    }
}

// 遍历线索化的二叉树
void PreOrderTraverse_Thr(BiThrTree T)
{
    BiThrTree p;
    p = T->lchild;
    while (p != T)
    {
        while (p->LTag == Link)
        {
            printf("%c", p->data);
            p = p->lchild;
        }
        printf("%c", p->data);
        p = p->rchild;
    }
}

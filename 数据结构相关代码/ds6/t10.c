// 某表达式用一棵二叉链表存储，编写算法输出该表达式的中缀形式，加上必要的括号。
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *lchild, *rchild;
} BTNode;

int getPri(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

void print(BTNode *root, int pri)
{
    if (root != NULL)
    {
        // 如果当前结点有左右孩子，则表示当前结点为运算符
        if (root->lchild != NULL || root->rchild != NULL)
        {
            if (getPri(root->data) <= pri)
                printf("(");
            print(root->lchild, getPri(root->data)); // 递归输出左子树
            printf("%c", root->data);
            print(root->rchild, getPri(root->data)); // 递归输出右子树
            if (getPri(root->data) <= pri)
                printf(")");
        }
        else
        {
            printf("%c", root->data);
        }
    }
}

int main(int argc, char const *argv[])
{
    BTNode *p = (BTNode *)malloc(sizeof(BTNode));
    p->data = '/';

    p->lchild = (BTNode *)malloc(sizeof(BTNode));
    p->lchild->data = '*';

    p->lchild->lchild = (BTNode *)malloc(sizeof(BTNode));
    p->lchild->lchild->data = 'a';
    p->lchild->lchild->lchild = NULL;
    p->lchild->lchild->rchild = NULL;

    p->lchild->rchild = (BTNode *)malloc(sizeof(BTNode));
    p->lchild->rchild->data = 'b';
    p->lchild->rchild->lchild = NULL;
    p->lchild->rchild->rchild = NULL;

    p->rchild = (BTNode *)malloc(sizeof(BTNode));
    p->rchild->data = '/';

    p->rchild->lchild = (BTNode *)malloc(sizeof(BTNode));
    p->rchild->lchild->data = 'c';
    p->rchild->lchild->lchild = NULL;
    p->rchild->lchild->rchild = NULL;

    p->rchild->rchild = (BTNode *)malloc(sizeof(BTNode));
    p->rchild->rchild->data = 'd';
    p->rchild->rchild->lchild = NULL;
    p->rchild->rchild->rchild = NULL;
    print(p, -1);
    return 0;
}

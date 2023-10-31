#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    struct tnode *lchild;
    struct tnode *rchild;
    int data;
} tnode;

// 先序遍历
void preorder(tnode *root)
{
    if (root != NULL)
    {
        printf("%c ", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

// 中序遍历
void inorder(tnode *root)
{
    if (root != NULL)
    {
        inorder(root->lchild);
        printf("%c ", root->data);
        inorder(root->rchild);
    }
}

// 后序遍历
void postorder(tnode *root)
{
    if (root != NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%c ", root->data);
    }
}

// 给定先序和中序序列，构造二叉树
tnode *create(int *pre, int *in, int n)
{
    if (n <= 0)
        return NULL;
    tnode *root = (tnode *)malloc(sizeof(tnode));
    root->data = pre[0];
    int i;
    for (i = 0; i < n; i++)
        if (in[i] == pre[0])
            break;
    root->lchild = create(pre + 1, in, i);
    root->rchild = create(pre + i + 1, in + i + 1, n - i - 1);
    return root;
}

int main(int argc, char const *argv[])
{
    // ABDEGCF
    int pre[] = {'A', 'B', 'D', 'E', 'G', 'C', 'F'};
    // DBEGACF
    int in[] = {'D', 'B', 'E', 'G', 'A', 'C', 'F'};

    tnode *root = create(pre, in, 7);
    postorder(root);

    return 0;
}


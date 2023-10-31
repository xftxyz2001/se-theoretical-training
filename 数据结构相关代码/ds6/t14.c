// 某二叉树采用顺序存储，判断该二叉树是否为二叉排序树。下标从1开始，n为最后一个元素的下标。
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

int isBST(ElemType A[], int n)
{
    int i;
    for (i = 0; i <= n; i++)
    {

        if (2 * i + 1 <= n && A[2 * i + 1] > A[i] || // 左子树大于根节点
            2 * i + 2 <= n && A[2 * i + 2] < A[i]    // 右子树小于根节点
        )
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    ElemType A[] = {0, 1, 2, 3, 4, 5, 6, 7};
    printf("%d\n", isBST(A, sizeof(A) / sizeof(A[0]) - 1));

    ElemType B[] = {5, 2, 7, 1, 3, 6, 9};
    printf("%d\n", isBST(B, sizeof(B) / sizeof(B[0]) - 1));
    return 0;
}

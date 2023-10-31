#include <stdio.h>
#include <stdlib.h>

// 将先序遍历序列pre[i1]...pre[j1]，转换为后序遍历序列post[i2]...post[j2]。

typedef char ElemType;

int getMid(int i, int j)
{
    return (j - i) / 2 + i;
}

void change(ElemType pre[], int i1, int j1, ElemType post[], int i2, int j2)
{
    if (i1 < j1)
    {
        change(pre, i1 + 1, getMid(i1 + 1, j1), post, i2, getMid(i2, j2 - 1));
        change(pre, getMid(i1 + 1, j1) + 1, j1, post, getMid(i2, j2 - 1) + 1, j2 - 1);
    }
    post[j2] = pre[i1];
}

// error
void change1(ElemType pre[], int i1, int j1, ElemType post[], int i2, int j2)
{
    if (i1 < j1)
    {
        post[j2] = pre[i1];
        change1(pre, i1 + 1, getMid(i1 + 1, j1), post, i2, getMid(i2, j2 - 1));
        change1(pre, getMid(i1 + 1, j1) + 1, j1, post, getMid(i2, j2 - 1) + 1, j2 - 1);
    }
}

// error
void change2(ElemType pre[], int i1, int j1, ElemType post[], int i2, int j2)
{
    if (i1 == j1)
    {
        post[j2] = pre[i1];
        return;
    }
    change2(pre, i1 + 1, getMid(i1 + 1, j1), post, i2, getMid(i2, j2 - 1));
    change2(pre, getMid(i1 + 1, j1) + 1, j1, post, getMid(i2, j2 - 1) + 1, j2 - 1);
}

int main(int argc, char const *argv[])
{
    ElemType pre[] = "ABCDEFG";
    ElemType post[7] = {0};
    change(pre, 0, 6, post, 0, 6);

    for (int i = 0; i < 7; i++)
        printf("%c ", post[i]);
    printf("\n");
    return 0;
}
#include <stdio.h>

// 假设并查集最多含有100个元素
#define MAX_SIZE 5

int parent[MAX_SIZE];

// 初始化并查集
void makeSet(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
}

// 输出并查集
void printSet(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", parent[i]);
    }
    printf("\n");
}

// 查找x所在的集合的代表元素
int find(int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    else
    {
        return find(parent[x]);
    }
}

// 合并x和y所在的集合
void unionSet(int x, int y)
{
    parent[find(x)] = find(y);

}

// // 判断两点是否直接相连
// int hasSide(int a[MAX_SIZE][MAX_SIZE], int x, int y)
// {
//     return a[x][y] == 1;
// }

// 判断两点是否连通
int isConnect(int x, int y)
{
    // printf("%d, %d, %d, %d\n", x, y, find(x), find(y));
    return find(x) == find(y);
}

int isLoop(int a[MAX_SIZE][MAX_SIZE], int n) // a[][]
{
    // 初始化并查集
    makeSet(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            // 如果两点已经连通
            if (isConnect(i, j))
            {
                return 1; // 有环
            }

            // 两点之间有边
            if (a[i][j] == 1)
            {
                // 两点联通，合并两点所在的集合
                unionSet(i, j);
            }
        }
    }
    return 0; // 无环
}

int main(int argc, char const *argv[])
{
    int a[MAX_SIZE][MAX_SIZE] = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}};

    printf("res:%d\n", isLoop(a, MAX_SIZE));
    return 0;
}

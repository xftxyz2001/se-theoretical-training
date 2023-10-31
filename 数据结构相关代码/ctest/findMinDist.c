#include <stdio.h>
#include <stdlib.h>

// 实现min函数
int min(int a, int b, int c, int i, int j, int k)
{
    if (a <= b && a <= c)
        return i;
    else if (b <= a && b <= c)
        return j;
    else
        return k;
}

int findMinDist(int s1[], int s2[], int s3[], int n1, int n2, int n3)
{
    int min_dist = INT_MAX;
    int dist;
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2 && k < n3)
    {
        dist = abs(s1[i] - s2[j]) + abs(s2[j] - s3[k]) + abs(s3[k] - s1[i]);
        if (dist < min_dist)
            min_dist = dist;
        int x = min(s1[i], s2[j], s3[k], i, j, k); // 返回最小值的下标
        if (x == i)
            i++;
        else if (x == j)
            j++;
        else
            k++;
    }
    printf("%d %d %d\n", s1[i], s2[j], s3[k]);
    return min_dist;
}
int main(int argc, char const *argv[])
{
    int s1[] = {-1, 0, 9};
    int s2[] = {-25, -10, 10, 11};
    int s3[] = {2, 9, 17, 30, 41};

    int n1 = sizeof(s1) / sizeof(s1[0]);
    int n2 = sizeof(s2) / sizeof(s2[0]);
    int n3 = sizeof(s3) / sizeof(s3[0]);

    printf("%d\n", findMinDist(s1, s2, s3, n1, n2, n3));
    return 0;
}

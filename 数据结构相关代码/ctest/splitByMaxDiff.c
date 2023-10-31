/**
 * 已知由n（n≥2）个正整数构成的集合A={ai}（0≤i<n），
 * 将其划分为两个不相交的子集A1和A2，元素个数分别是n1和n2，
 * A1和A2中元素之和分别为S1和S2。
 * 设计一个尽可能高效的划分算法，
 * 满足|n1-n2|最小且|S1-S2|最大，
 * 输出|n1-n2|和|S1-S2|的值。
 */

#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int splitByMaxDiff(int arr[], int n)
{
    qsort(arr, n, sizeof(int), cmpfunc);
    int sum1 = 0, sum2 = 0;
    int i = 0;
    for (i = 0; i < n / 2; i++)
    {
        sum1 += arr[i];
    }
    for (; i < n; i++)
    {
        sum2 += arr[i];
    }
    return sum2 - sum1;
}
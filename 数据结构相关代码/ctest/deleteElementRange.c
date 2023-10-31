/**
 * 设计算法，删除整数顺序表L中所有值在[x，y]范围内的元素。要求时间复杂度为O(n)，空间复杂度为O(1)。
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int last;
    int maxSize;
} SeqList;

void deleteElementRange(SeqList L, int x, int y)
{
    int i = 0;
    for (int j = 0; j <= L.last; j++)
    {
        if (L.data[j] < x || L.data[j] > y)
        {
            L.data[i] = L.data[j];
            i++;
        }
    }
    L.last = i - 1;
}

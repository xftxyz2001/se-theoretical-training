/**
 * 在顺序表L中，删除第一个值最大的元素。
 * 如顺序表L=（3,1,6,3,6,4,2,6）,删除后L=（3,1,3,6,4,2,6）
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int last;
    int maxSize;
} SeqList;

void deleteFirstLargeElement(SeqList L)
{
    int max = L.data[0];
    int maxIndex = 0;
    for (int i = 1; i <= L.last; i++)
    {
        if (L.data[i] > max)
        {
            max = L.data[i];
            maxIndex = i;
        }
    }
    for (int i = maxIndex; i < L.last; i++)
    {
        L.data[i] = L.data[i + 1];
    }
    L.last--;
}

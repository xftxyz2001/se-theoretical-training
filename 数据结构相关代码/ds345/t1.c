// 1到n的火车，按某种排列依次从入口进入车站，车站中有若干轨道可供调度使用。
// 如果在出口出站的顺序必须是1,2,3，..., n，
// 设计算法，求给定的进站排列至少需要多少个调度轨道。

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// 一条轨道
// typedef struct
// {
//     int data[MAX];
//     int top;
// } Stack;

// 所有轨道
// typedef struct
// {
//     Stack *s;
//     int n;
// } Station;

// 输出所有轨道
// void printTrack(Station *st)
// {
//     for (int i = 0; i < st->n; i++)
//     {
//         printf("Track %d: ", i + 1);
//         for (int j = 0; j <= st->s[i].top; j++)
//         {
//             printf("%d ", st->s[i].data[j]);
//         }
//         printf("\n");
//     }
// }

// 计算最少需要多少个调度轨道
int minTrack(int *a, int n)
{
    // 记录每条轨道上排队的最后一个火车的编号
    int *track = (int *)malloc(sizeof(int) * n);
    // 初始化所有轨道为空
    for (int i = 0; i < n; i++)
    {
        track[i] = -1;
    }

    // min记录最少需要多少个调度轨道
    int min = 0;

    // 遍历所有火车
    for (int i = 0; i < n; i++)
    {
        // 遍历所有轨道，找到比当前火车大且最接近当前火车的轨道
        int j = 0;
        int k = -1; // 记录最接近当前火车的轨道
        while (j < n && track[j] != -1)
        {
            // 找到比当前火车小的火车
            if (track[j] < a[i])
            {
                // 如果当前轨道比最接近当前火车的轨道大，则更新最接近当前火车的轨道
                if (k < 0 || track[j] > track[k])
                {
                    k = j;
                }
                // break;
            }
            // 如果当前轨道比最接近当前火车的轨道小，则更新最接近当前火车的轨道
            // if (track[j] < track[k])
            // {
            //     k = j;
            // }
            j++;
        }
        // 如果没有比当前火车小的火车，则将当前火车放入j轨道
        if (k == -1)
        {
            k = j;
        }
        // 将当前火车放入该轨道
        track[k] = a[i];
        // 如果当前轨道数大于min，则更新min
        if (k > min)
        {
            min = k;
        }
    }
    return min + 1;
    //     Station *st = (Station *)malloc(sizeof(Station));
    //     st->s = (Stack *)malloc(sizeof(Stack) * n);
    //     st->n = n;

    //     // 初始化所有轨道为空
    //     for (int i = 0; i < n; i++)
    //     {
    //         st->s[i].top = -1;
    //     }

    //     // min记录最少需要多少个调度轨道
    //     int min = 0;

    //     // 遍历所有火车
    //     for (int i = 0; i < n; i++)
    //     {
    //         // 遍历所有轨道
    //         int j = 0;
    //         while (j < n)
    //         {
    //             // 找到第一个空轨道或者比当前火车大的火车
    //             if (st->s[j].top == -1 || st->s[j].data[st->s[j].top] > a[i])
    //             {
    //                 // 将当前火车放入该轨道
    //                 st->s[j].data[++st->s[j].top] = a[i];
    //                 break;
    //             }
    //             j++;
    //         }
    //         // 如果当前轨道数大于min，则更新min
    //         if (j > min)
    //         {
    //             min = j;
    //         }
    //     }
    //     printTrack(st);
    //     return min + 1;
}

int main(int argc, char const *argv[])
{
    int a[] = {7, 6, 1, 9, 3, 5, 2, 4, 8};
    int n = sizeof(a) / sizeof(int);
    printf("%d\n", minTrack(a, n));
    return 0;
}

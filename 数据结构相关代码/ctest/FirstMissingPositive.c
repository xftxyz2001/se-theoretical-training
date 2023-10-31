/**
 * 未出现的最小正整数
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// 随机生成一个长度为n的数组，绝对值越小的数出现的概率越大
int *generateRandomArray(int n, unsigned int seed)
{
    srand(seed);
    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int sign = rand() % 2 == 0 ? 1 : -1;
        double r = ((double)rand() / RAND_MAX);
        double x = log(1 - r) / log(1.0 / 4.0);
        int num = (int)(x * n / 4 + 0.5);

        arr[i] = sign * num;
    }

    return arr;
}

// 打印数组
void printArray(int *arr, int n, int line_length)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
        if ((i + 1) % line_length == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}

// 比较函数
int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// 调用函数实现快速排序
void quickSort(int *arr, int n)
{
    qsort(arr, n, sizeof(int), cmpfunc);
}

// 未出现的最小正整数（哈希法）
int firstMissingPositiveHash(int *nums, int numsSize)
{
    // 初始化哈希表
    int *hash = (int *)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        hash[i] = 0;
    }
    // 遍历数组，将出现的正整数对应的哈希表位置置为1
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > 0 && nums[i] <= numsSize)
        {
            hash[nums[i] - 1] = 1;
        }
    }
    // 遍历哈希表，找到第一个为0的位置，即为未出现的最小正整数
    for (int i = 0; i < numsSize; i++)
    {
        if (hash[i] == 0)
        {
            return i + 1;
        }
    }
    return numsSize + 1;
}

// 未出现的最小正整数（排序法）
int firstMissingPositiveSort(int *nums, int numsSize)
{
    // 排序
    quickSort(nums, numsSize);
    // 跳过负数
    int i = 0;
    while (i < numsSize && nums[i] <= 0)
    {
        i++;
    }
    // 从1开始遍历，找到第一个不在数组中的正整数
    int min = 1;
    while (i < numsSize)
    {
        if (nums[i] == min)
        {
            min++;
        }
        else if (nums[i] > min)
        {
            return min;
        }
        i++;
    }
    return min;
}

// 未出现的最小正整数（交换法）
int findFirstMissingPositive(int *nums, int numsSize)
{
    int i = 0;
    while (i < numsSize)
    {
        // nums[i] > 0 && nums[i] <= numsSize 不考虑负数和大于数组长度的数（因为数组长度为n，极限情况下，数组中的数为1~n）
        // nums[nums[i] - 1] != nums[i] 元素不在正确的位置上，交换，直到元素在正确的位置上
        if (nums[i] > 0 && nums[i] <= numsSize && nums[nums[i] - 1] != nums[i])
        {
            int temp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
        }
        else
        {
            i++;
        }
    }
    // 遍历数组，找到第一个不在正确位置上的元素，返回位置应有的元素
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] != i + 1)
        {
            return i + 1;
        }
    }
    return numsSize + 1;
}

int main(int argc, char const *argv[])
{
    // 数组长度
    int n = 20;
    int rand_seed = 3;
    // 生成随机数组
    int *arr = generateRandomArray(n, rand_seed);
    quickSort(arr, n);
    // 打印数组
    printArray(arr, n, 10);

    arr = generateRandomArray(n, rand_seed);
    printf("%d\n", firstMissingPositiveHash(arr, n));

    arr = generateRandomArray(n, rand_seed);
    printf("%d\n", firstMissingPositiveSort(arr, n));

    arr = generateRandomArray(n, rand_seed);
    printf("%d\n", findFirstMissingPositive(arr, n));

    return 0;
}

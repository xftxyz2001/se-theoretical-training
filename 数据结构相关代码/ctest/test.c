#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// int abs(int n)
// {
//     return n < 0 ? -n : n;
// }

int findMinDist(int s1[], int s2[], int s3[], int n1, int n2, int n3)
{
    int min_dist = INT_MAX;
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2 && k < n3) // 当其中一个数组结束后，不存在更小的距离
    {
        // T(n) = O(n1+n2+n3)
        int dist = abs(s1[i] - s2[j]) + abs(s2[j] - s3[k]) + abs(s1[i] - s3[k]);
        if (dist < min_dist)
        {
            min_dist = dist;
        }
        if (s1[i] <= s2[j] && s1[i] <= s3[k])
        {
            i++;
        }
        else if (s2[j] <= s1[i] && s2[j] <= s3[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }
    return min_dist;
}

int main(int argc, char const *argv[])
{
    return 0;
}

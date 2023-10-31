#define bool int
#define true 1
#define false 0

bool canThreePartsEqualSum(int *arr, int arrSize)
{
    int sum = 0;
    int i;
    for (i = 0; i < arrSize; i++)
    {
        sum += arr[i];
    }
    if (sum % 3 != 0)
    {
        return false;
    }

    sum /= 3; // 每一部分的和
    int temp = 0;
    for (i = 0; i < arrSize; i++)
    {
        temp += arr[i];
        if (temp == sum)
        {
            break;
        }
    }
    if (i >= arrSize)
    {
        return false;
    }
    temp = 0;
    for (; i < arrSize; i++)
    {
        temp += arr[i];
        if (temp == sum)
        {
            break;
        }
    }
    return i < arrSize;
}
// [3,3,6,5,-2,2,5,1,-9,4]
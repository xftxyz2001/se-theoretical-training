#include <stdio.h>

int main(int argc, char const *argv[])
{
    // int arr[9][4][2];
    int arr[10][5][3] = {0};
    printf("%d\n", &arr[0][0][0]);
    printf("%d\n", &arr[0][0][1]);
    printf("%d\n", &arr[4][2][2]);

    return 0;
}

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    const int n = 3;
    int arr[n][n] = {
        {4, 9, 2},
        {3, 5, 7},
        {8, 1, 6}};

    // int target = (1 + n * n) * (n * n) / 2 / n;
    int target = (n * (n * n + 1)) / 2;

    int sum_diag1 = 0, sum_diag2 = 0;
    for (int i = 0; i < n; i++)
    {
        int sum_row = 0, sum_col = 0;
        for (int j = 0; j < n; j++)
        {
            sum_row += arr[i][j];
            sum_col += arr[j][i];
        }
        if (sum_row != target || sum_col != target)
        {
            cout << "Not a magic square" << endl;
            return 0;
        }
        sum_diag1 += arr[i][i];
        sum_diag2 += arr[i][n - i - 1];
    }

    // int sum_diag1 = 0, sum_diag2 = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     sum_diag1 += arr[i][i];
    //     sum_diag2 += arr[i][n - i - 1];
    // }

    if (sum_diag1 != target || sum_diag2 != target)
    {
        cout << "Not a magic square" << endl;
        return 0;
    }

    cout << "It's a magic square" << endl;

    return 0;
}

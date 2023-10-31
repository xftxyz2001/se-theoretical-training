#include <iostream>
#include <stack>
using namespace std;

bool IsLegal(int a[], int n)
{
    stack<int> s;
    for (int i = 0, k = 1; i < n; i++)
    {
        while (a[i] >= k)
            s.push(k++);
        if (a[i] < s.top())
            break;
        if (a[i] == s.top())
            s.pop();
    }
    return s.empty();
}

int main(int argc, char const *argv[])
{
    int a[] = {4, 1, 3, 2, 6};
    cout << IsLegal(a, sizeof(a) / sizeof(int)) << endl;
    return 0;
}

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int num;
    cin >> num;

    bool result = true;
    int i = 2;
    while (i < num)
    {
        if (num % i == 0)
        {
            result = false;
            break;
        }
        i++;
    }
    if (result)
    {
        cout << num << "is prime" << endl;
    }
    else
    {
        cout << num << "is not prime" << endl;
    }
    return 0;
}

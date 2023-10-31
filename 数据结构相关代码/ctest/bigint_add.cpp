#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string num1 = "123";
    string num2 = "456";

    string result = "";

    int p1 = num1.size() - 1;
    int p2 = num2.size() - 1;

    int carry = 0; // 进位
    while (p1 >= 0 || p2 >= 0 || carry)
    {
        int n1 = p1 >= 0 ? num1[p1] - '0' : 0;
        int n2 = p2 >= 0 ? num2[p2] - '0' : 0;

        int sum = n1 + n2 + carry;
        carry = sum / 10;
        // result += sum % 10 + '0';
        result = (char)(sum % 10 + '0') + result;

        p1--;
        p2--;
    }

    // if (carry)
    // {
    //     result += carry + '0';
    // }

    cout << result << endl;

    return 0;
}

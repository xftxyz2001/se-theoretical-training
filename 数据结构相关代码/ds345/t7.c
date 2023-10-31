#include <stdio.h>


int fun(int n)
{

    if (n == 1)
        return 1;

    if (n % 2 == 0)
        return n + fun(n / 2);

    else
        return n + fun(n - 1);
}


int main(int argc, char const *argv[])
{
    printf("%d\n", fun(7));
    return 0;
}

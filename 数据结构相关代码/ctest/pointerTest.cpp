#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int i = 0;
    const int c = 1;

    int *p = &i;                         // 普通指针
    const int *cp = &c, *cp2 = &i;       // 指向常量的指针，指针指向的值不能改变
    int *const pc = &i, *const pc2 = &i; // 常量指针，指针本身的值不能改变

    // 指针数组
    int *pa[10]; // 指针数组，数组中的元素都是指针
    // 数组指针
    int(*ap)[10]; // 数组指针，指向数组的指针
    const int *const cpc = &c;
}

#include <iostream>
#include <string>
using namespace std;

struct PrivateStruct
{
    string name;
    int age;
};

struct PublicStruct
{
};

PublicStruct *createStruct()
{
    PrivateStruct *ps = new PrivateStruct;
    return (PublicStruct *)ps;
}

void setName(PublicStruct *s, string name)
{
    PrivateStruct *ps = (PrivateStruct *)s;
    ps->name = name;
}

string getName(PublicStruct *s)
{
    PrivateStruct *ps = (PrivateStruct *)s;
    return ps->name;
}

void setAge(PublicStruct *s, int age)
{
    PrivateStruct *ps = (PrivateStruct *)s;
    ps->age = age;
}

int getAge(PublicStruct *s)
{
    PrivateStruct *ps = (PrivateStruct *)s;
    return ps->age;
}

int main(int argc, char const *argv[])
{
    PublicStruct *s = createStruct();
    cout << "1" << endl;
    setName(s, "zhangsan");
    cout << "1" << endl;
    setAge(s, 20);
    cout << "1" << endl;

    cout << "name = " << getName(s) << endl;
    cout << "age = " << getAge(s) << endl;

    // int *np = nullptr;
    // cout << "np = " << np << endl;
    // if (np)
    // {
    //     cout << "np is not null" << endl;
    // }
    // else
    // {
    //     cout << "np is null" << endl;
    // }
    // void *vp = np;
    return 0;
}

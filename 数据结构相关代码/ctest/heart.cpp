#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // 设置输出颜色 红色
    cout << "\033[31m";
    
    // 爱心曲线方程 (x^2 + y^2 - a)^3 - x^2 * y^3 = 0
    // double a = 1;
    double a = 0.3;

    // 定义绘图边界
    double bound = 1.3 * sqrt(a);

    // x、y坐标变化步长
    double step = 0.05;
    for (double y = bound; y >= -bound; y -= step)
    {
        for (double x = -bound; x < bound; x += 0.5 * step)
        {
            // 代入曲线方程，计算每个点是否在曲线内
            double result = pow((pow(x, 2) + pow(y, 2) - a), 3) - pow(x, 2) * pow(y, 3);
            if (result <= 0)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << "\033[0m";
    cin.get();
    return 0;
}

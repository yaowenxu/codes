// 立方根迭代
// 编译公式：c++ -std=c++11 Q1.cc -o out ; ./out ; rm out

#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    freopen("Q1.in", "r", stdin); // 进行重定向输入到文件；
    double x, n; // 进行保存输入；
    while (scanf("%lf %lf", &x, &n) != EOF)
    {
        double y = x;
        for (int i = 0; i < n; i++)
        {
            // 进行迭代；
            y = y * 2 / 3 + x / (3*y*y); // 进行迭代计算；
        }
        printf("%.6lf\n", y);
    }
    
    return 0; // 进行返回值；
}
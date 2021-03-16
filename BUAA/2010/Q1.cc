#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std; 

double ccos(double x){
    double sum = 1.0;
    double tmp = 1.0;
    for (int i = 2; i < 20; i+=2)
    {
        tmp = x*x*tmp/(double(i*(i-1)))*(-1.0);
        if (fabs(tmp) < 1.e-7) 
        {
            break; // 当到一定程度，不进行计算；
        }
        sum += tmp;
    }
    return sum; // 输出cos的值；
}

int main(){
    freopen("Q1.in", "r", stdin); // 进行重定向输入到文件；
    double x;
    while (scanf("%lf", &x) != EOF)
    {
        // 输出变量；
        printf("cos(%1.4lf) = %1.4lf : %1.4lf\n", x, cos(x), ccos(x)); 
    }
    return 0;
}
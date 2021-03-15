// 真分数，求解真分数。
// 编译命令：c++ -std=c++11 Q1.cc -o out ; ./out ; rm out

#include <iostream>
#include <cstdio>
using namespace std;

int gcd (int a, int b){
    if (a % b == 0){
        return b;
    }else{
        return gcd(b, a%b);
    }
}

int gcd2(int a, int b){
    while (a % b != 0)
    {
        int  t = a % b;
        a = b;
        b = t;
    }
    return b;
}

int main()
{
    // 注意，真分数为大于0小于1的所有分数。
    // 这里限定了程序的输入。
    freopen("Q1.in", "r", stdin); // 进行重定向输入；
    cout << gcd2(4, 2) << endl;
    int first = 0;
    int second = 0;

    while (scanf("%d %d", &first, &second) != EOF)
    {
        int g = gcd(second, first);
        cout << first/g << " " << second/g << endl;
    }
    
    return 0;
}
// 相亲数
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

// 正整数，a 的约数和等于 b; 包含1，但是不包含b本身；
int sum(int n){
    int s = 0;
    int first = true;
    for (int i = 1; i < n; i++)
    {
        if (n%i==0)
        {
            s += i;
            if(first){
                first = false;
            }else{
                cout << "+";
            }
            cout << i;
        }
    }
    return s;
}

int main(){
    freopen("Q1.in", "r", stdin); // 重定向标准输入到文件；
    int a, b;
    while (scanf("%d %d", &a, &b)!=EOF)
    {
        cout << a << ",";
        int suma = sum(a);
        cout << "=" << suma << endl;
        cout << b << ",";
        int sumb = sum(b);
        cout << "=" << sumb << endl;
        if (suma == b && sumb == a)
        {
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
    }
    return 0;
}
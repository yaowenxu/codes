#include <cstdio>
#include <iostream>

using namespace std;

bool sushu(int n){
    bool flag = true;
    for (int i = 2; i < n; i++)
    {
        if (n%i == 0)
        {
            return false;
        }
    }
    return true;
}

int main(){
    freopen("Q1.in", "r", stdin); // 进行重定向输入；
    int n = 0;
    while (scanf("%d", &n)!=EOF)
    {
        if (n <= 2)
        {
            cout << -1 << endl;
            continue;
        }
        bool out = false;
        // 进行判断素数；
        for (int i = 2; i < n; i++)
        {
            if (sushu(i))
            {
                if (i%10 == 1){
                    cout << i << " ";
                    out = true;
                }
            }
        }
        if (out)
        {
            cout << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}
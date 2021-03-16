// 孪生数；
#include <cstdio>
#include <iostream>

using namespace std;

int sum(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        int tmp = n / i;
        if (tmp *i == n)
        {
            sum += i; // 进行求和；
        }
    }
    return sum;
}

int main()
{
    freopen("Q1.in", "r", stdin); // 重定向标准输入输出；
    int m, n;
    while (scanf("%d %d", &m, &n) != EOF)
    {
        int flag = true;
        for(int i = m; i <= n; i++){
            if (i == 1)
            {
                continue; // 进行跳过；
            }
            int nother = sum(i);
            if (nother > i && nother <=n && sum(nother) == i)
            {
                cout << i << " " << nother << endl;
                flag = false; // 进行设置标记，说明孪生数存在；
            }
        }
        if (flag)
        {
            cout << "NONE" << endl;
        }
    }
    return 0;
}
// 编译命令:c++ -std=c++11 Q1.cc -o out ; ./out ; rm out

#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

int main(){
    freopen("Q1.in", "r", stdin);
    int num = 0;
    while (scanf("%d", &num)!=EOF)
    {
        bool flag = true; // 表示当前找到；
        for (int m = 1; m <= num/2; m++)
        {
            // 通过计算循环边界，进行减少搜索规模；
            for (int n = m+1; n <= num/2+1; n++)
            {
                if (((m+n)*(n-m+1)/2) == num)
                {
                    cout << num << " : ";
                    flag = false; // 表示当前找到；
                    for (int i = m; i <= n; i++)
                    {
                        cout << i << " "; // 进行输出；
                    }
                    cout << endl;
                }
            }
        }
        if (flag)
        {
            cout << "None" << endl;
        }
    }
    return 0;
}
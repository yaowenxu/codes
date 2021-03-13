// 阶乘数
// 编译命令：c++ -std=c++11 Q1.cc -o out ; ./out ; rm out
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
void solve(int num);

int main()
{
    // 注意此题，表示输入的都是正数；并且阶乘之和不会超出int类型；
    freopen("Q1_input.txt", "r", stdin); // 重定向到标准输入；
    int number;
    vector<int> vec;
    bool first = true;
    while (true) // 控制打印；
    {
        if (scanf("%d", &number) != EOF)
        {
            if (first == true)
            {
                solve(number);
                first = false;
            }else{
                cout << endl;
                solve(number);
            }
        }else{
            break;
        }
        // vec.push_back(number);
    }
    // for (int i = 0; i < vec.size(); i++)
    // {
    //     solve(vec[i]);
    //     if (i != vec.size() - 1)
    //     {
    //         cout << endl;
    //     }
    // }
    return 0;
}

int calc(int n)
{
    int ret = 1;
    for (int i = 1; i <= n; i++)
    {
        ret *= i;
    }
    return ret;
}

void solve(int num)
{
    int check = num;
    cout << num << ",";
    stack<int> stk;
    while (num / 10 != 0 || num % 10 != 0)
    {
        stk.push(num % 10);
        num /= 10;
    }
    int sum = 0;
    while (stk.size() != 0)
    {
        int n = stk.top();
        sum += calc(n);
        cout << n;
        stk.pop();
        if (stk.size() == 0)
        {
            cout << "!=";
        }
        else
        {
            cout << "!+";
        }
    }
    cout << sum << endl;
    if (sum == check)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}
// 五子棋 c++ -std=c++11 Q2.cc -o out ; ./out ; rm out
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

// 五子棋的序号从1开始；
// 题目说明保证输入样例每条线上至多只有连续的5个同色棋子；
// 题目保证至多只有1人获胜。
// 注意本程序进行对输入文件的处理；

void solve(vector<int> vec);

int main()
{
    freopen("Q2.in", "r", stdin); // 进行重定向输入到Q2.in文件；
    int max = 19 * 19;
    vector<int> vec;
    int cnt = 0;
    int num = 0;

    // 进行输入输出处理；
    while (scanf("%d", &num) != EOF)
    {
        vec.push_back(num);
        if (vec.size() == max)
        {
            solve(vec);
            vec.clear();
        }
    }

    return 0;
}

bool check_win(int space[19][19], int i, int j)
{
    int now = space[i][j];
    if (now == 0)
    {
        return false;
    }
    
    if ((i + 5 < 19) && (j + 5 < 19))
    {
        int flag1 = true;
        int flag2 = true;
        int flag3 = true;
        // 检查竖行；
        for (int ii = 0; ii < 5; ii++)
        {
            if (space[i + ii][j] != now)
            {
                flag1 = false;
                break;
            }
        }

        // 检查横行；
        for (int jj = 0; jj < 5; jj++)
        {
            if (space[i][j + jj] != now)
            {
                flag2 = false;
                break;
            }
        }

        // 检查对角线1；
        for (int ij = 0; ij < 5; ij++)
        {
            if (space[i + ij][j + ij] != now)
            {
                flag3 = false;
                break;
            }
        }

        if (flag1 || flag2 || flag3 )
        {
            return true; // 进行返回正确值；
        }
    }

    // 检查对角线2；
    if ((j - 4 >= 0) && (i + 5 < 19))
    {
        int flag4 = true;
        for (int ij = 0; ij < 5; ij++)
        {
            if (space[i + ij][j - ij] != now)
            {
                flag4 = false;
                break;
            }
        }
        if (flag4)
        {
            return true; // 进行返回正确值；
        }
    }
    return false;
}

void solve(vector<int> vec)
{
    int space[19][19]; // 创建棋盘空间；
    for (int i = 0; i < 19 * 19; i++)
    {
        space[i / 19][i % 19] = vec[i]; // 进行对棋盘赋值；
    }

    bool win = false;

    // 遍历棋盘；假设此处的从左到右的情况，最小；
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            win = check_win(space, i, j);
            if (win)
            {
                cout << space[i][j] << ":" << i+1 << "," << j+1 << endl;
                return;
            }
        }
    }

    if (win == false)
    {
        cout << "no" << endl; // 此处注意判断题目中对最后一行的处理；
    }
}
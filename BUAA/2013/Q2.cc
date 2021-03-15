// 八皇后简单版
// 编译命令：c++ -std=c++11 Q2.cc -o out ; ./out ; rm out
// https://www.cnblogs.com/smile233/p/8483729.html

#include <iostream>
#include <cstdio>
#define SIZE 8
using namespace std;

bool check(bool arr[SIZE][SIZE], int i, int j)
{
    // 进行重新检查是否合适；

    // 检查纵向；
    int row = i - 1;
    while (row >= 0)
    {
        if (arr[row][j])
        {
            return false;
        }
        row --;
    }

    // 检查正对角线
    row = i - 1;
    int col =  j - 1;
    while (row >= 0 && col >= 0)
    {
        if (arr[row][col])
        {
            return false;
        }
        row --;
        col --;
    }

    // 检查副对角线
    row = i - 1;
    col = j + 1;
    while (row >= 0 && col < SIZE)
    {
        if(arr[row][col])
        {
            return false;
        }
        row --; // 进行减行；
        col ++; // 进行增加列；
    }
    return true;
}

int cnt = 0; // 序列

void output(bool arr[SIZE][SIZE])
{
    cout << " " << " === " << ++cnt << " === " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(bool arr[SIZE][SIZE], int row)
{
    // 其中row表示当前解决第几行；
    for (int col = 0; col < SIZE; col++)
    {
        arr[row][col] = true;
        // col 表示遍历第几列；
        if (check(arr, row, col))
        {
            if (row + 1 == SIZE)
            {
                /* code */
                output(arr); // 满足情况，进行输出；
            }
            else
            {
                solve(arr, row + 1); // 通过 row + 1；进行减治，缩小问题规模。
            }
        }
        arr[row][col] = false; // 进行回溯；
    }
}

int main()
{
    cout << "八皇后问题：" << endl;
    bool arr[SIZE][SIZE]; // 进行初始化棋盘大小；
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            arr[i][j] = false; // 初始化为false;
        }
    }
    solve(arr, 0); // 求解问题；
    cout << "总共解法：" << cnt << " 种。" << endl;
    return 0;
}

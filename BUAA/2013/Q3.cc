// 科学计数法
// 编译命令：c++ -std=c++11 Q3.cc -o out ; ./out ; rm out

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

// 题目理解，输入为一个标准的正数；且开头和末尾没有多余的零；注意其输入的是标准的正数。

int main()
{
    // 进行转换为科学计数法；
    freopen("Q3.in", "r", stdin);
    char buffer[200];
    memset(buffer, 0, 200);
    while (fgets(buffer, 200, stdin) != NULL)
    {
        // 去掉换行。
        if (buffer[strlen(buffer) - 1] == '\n')
        {
            buffer[strlen(buffer) - 1] = '\0';
        }
        // 获取点的位置；
        int dot = -1; // -1 表示位置不存在。
        for (int i = 0; i < strlen(buffer); i++)
        {
            if (buffer[i] == '.')
            {
                dot = i;
            }
        }

        // 如果dot==-1表示为正数；
        if (dot == -1)
        {
            if (strlen(buffer) == 1)
            {
                cout << buffer << endl;
                memset(buffer, 0, 200);
                continue;
            }
            else
            {
                for (int i = 0; i < strlen(buffer); i++)
                {
                    if (i == 1)
                    {
                        cout << ".";
                    }
                    cout << buffer[i];
                }
                cout << "e" << strlen(buffer) - 1 << endl;
            }
        }
        else
        {
            if (dot == 1)
            {
                if (strlen(buffer) == 3)
                {
                    cout << buffer << endl;
                }
                else
                {
                    // 计算 后面的位数，进行输出e 0.002 1.002
                    if (buffer[0] == '0')
                    { // 输出e-x
                        int cnt = 0;
                        int i = 0;
                        for (i = 0; i < strlen(buffer); i++)
                        {
                            if (i > dot)
                            {
                                cnt++;
                            }
                            if (buffer[i] != '0' && i != dot)
                            {
                                break;
                            }
                        }
                        for (int j = i; j < strlen(buffer); j++)
                        {
                            cout << buffer[j];
                            if (strlen(buffer) - j != 1 && j == i)
                            {
                                cout << ".";
                            }
                        }
                        cout << "e-" << cnt << endl;
                    }
                    else
                    { // 输出 ex
                        cout << buffer << endl;
                    }
                }
            }
            else
            {
                // 计算，后面和前面的位数，输出e; 12.345
                int cnt = 0;
                for (int i = 0; i < strlen(buffer); i++)
                {
                    if (i == 1)
                    {
                        cout << ".";
                    }
                    if (buffer[i] == '.')
                    {
                        cnt = i - 1;
                        continue; // 跳过输出；
                    }
                    cout << buffer[i];
                }
                cout << "e" << cnt << endl;
            }
        }

        // 最后都会情况buffer;
        memset(buffer, 0, 200);
    }
    return 0;
}

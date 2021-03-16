//统计关键字出现位置；

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

bool is_symbol(char c)
{
    switch (c)
    {
    case ' ':
    case '(':
    case '{':
    case ';':
        return true;
        break;
    default:
        return false;
        break;
    }
}

int main()
{
    freopen("Q3.in", "r", stdin); // 进行重定向文件输入；
    while (true)
    {
        char codes[310];       // 代码；
        memset(codes, 0, 310); // 进行设置为空；
        if (fgets(codes, 300, stdin) == NULL)
        {
            break; // 进行中断循环；
        }
        int flag = false;
        for (int i = 0; i < 300; i++)
        {
            if (codes[i] == '\0')
            {
                break;
            }
            if (codes[i] == '\"')
            {
                flag = !flag; // 跳过双引号内部的字符；
            }
            if (flag)
            {
                continue;
            }

            // 判断if;
            if (codes[i] == 'i')
            {
                if (codes[i + 1] == 'f' && codes[i + 1] != '\0')
                {
                    if (i - 1 >= 0)
                    {
                        if (is_symbol(codes[i - 1]) && is_symbol(codes[i + 2]))
                        {
                            cout << "if:" << i + 1 << endl;
                        }
                    }
                }
            }

            // 判断while
            if (codes[i] == 'w')
            {
                if (codes[i + 1] == 'h' && codes[i + 1] != '\0' && codes[i + 2] == 'i' && codes[i + 2] != '\0' && codes[i + 3] == 'l' && codes[i + 3] != '\0' && codes[i + 4] == 'e' && codes[i + 4] != '\0')
                {
                    if (i - 1 >= 0)
                    {
                        if (is_symbol(codes[i - 1]) && is_symbol(codes[i + 5]))
                        {
                            cout << "while:" << i + 1 << endl;
                        }
                    }
                }
            }

            // 判断 for; 此处使用了一次循环；
            if (codes[i] == 'f')
            {
                if (codes[i + 1] == 'o' && codes[i + 1] != '\0' && codes[i + 2] == 'r' && codes[i + 2] != '\0')
                {
                    if (i - 1 >= 0)
                    {
                        if (is_symbol(codes[i - 1]) && is_symbol(codes[i + 3]))
                        {
                            cout << "for:" << i + 1 << endl;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
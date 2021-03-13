// 编译命令：c++ -std=c++11 Q3.cc -o out ; ./out ; rm out

#include <iostream>
#include <cstring>
using namespace std;

// 题目保证位置号比各行冒号前的最大字符数还要大。最多100个字符。
// 强调了最后一个单词后不加空格，直接换行。
// 因为题目中限定了异常的输入和输出，所以题目难度较低。

void out_blank(int num)
{
    for (int i = 0; i < num; i++)
    {
        cout << " ";
    }
}

int main()
{
    freopen("Q3.in", "r", stdin); // 重定向输入；
    int index = 0;
    scanf("%d", &index);
    int front_end_count = index - 1;
    while (true)
    {
        char first_buf[100];
        char second_buf[100];
        memset(first_buf, 0, 100);
        memset(second_buf, 0, 100);
        if (scanf("%s : %s", first_buf, second_buf) != EOF)
        {
            out_blank(front_end_count-strlen(first_buf)); // 显示第一个buf的大小；
            cout << first_buf << " : " << second_buf << endl;
        }else{
            break;
        }
    }

    return 0;
}
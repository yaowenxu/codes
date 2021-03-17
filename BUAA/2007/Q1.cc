#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    freopen("Q1.in", "r", stdin); // 重定向文件到输入；
    char c; // 字符
    int blank_cnt = 0;
    int tab_cnt = 0;
    int enter_cnt = 0;
    while (scanf("%c", &c)!=EOF)
    {
        if (c == ' ')
        {
            blank_cnt ++;
        }
        if (c == '\n')
        {
            enter_cnt++;
        }
        if (c == '\t')
        {
            tab_cnt++;
        }
    }
    cout << "blank: " << blank_cnt << endl;
    cout << "tab: " << tab_cnt << endl;
    cout << "enter: " << enter_cnt << endl;
    return 0;
}
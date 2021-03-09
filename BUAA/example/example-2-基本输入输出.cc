// 编译指令：c++ -std=c++11 example-2.cc -o out ; ./out; rm out
// r+ 具有读写属性，从文件开始处写，保留原有文件中没有被覆盖的内容；
// w+ 具有读写属性，写的时候如果文件存在，会被清空，从头开始写；

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

void func_redirect_to_file();
void func_redirect_to_console_linux();
void func_redirect_to_console_windows();
void input_on_c();  // 输出；
void output_on_c(); // 输出；
char buffer[256];   // 全局变量；

int main()
{
    func_redirect_to_file(); // 输入输出重定向到文件；
    input_on_c();

    scanf("%s", buffer);
    cout << buffer << " " << strlen(buffer) << endl;

    // func_redirect_to_console_linux(); // 输入输出重新定向为标准输入输出；
    // func_redirect_to_console_windows();

    scanf("%s", buffer);
    cout << buffer << " " << strlen(buffer) << endl;

    output_on_c();
    return 0;
}

void input_on_c()
{ // c语言输入方法；
    // scanf getchar fgets; getch getche 为 windows 特有；
    char str[100];
    fgets(str, 100, stdin); // 读入包含换行符；
    puts(str);
    cout << strlen(str) << endl;
    exit(0);
}

void output_on_c()
{ // c语言输出方法；
    // puts printf putchar
    while (scanf("%s", buffer) != EOF)
    {
        puts(buffer); // 换行输出；
    }
}

void func_redirect_to_file()
{
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
}

void func_redirect_to_console_linux()
{ // 适用于 linux 系统；
    // 进行重定向
    freopen("/dev/tty", "r", stdin);
    // freopen("/dev/tty", "w", stdout);
}

void func_redirect_to_console_windows()
{ // 适用于 windows 系统；
    freopen("CON", "r", stdin);
    // freopen("CON", "w", stdout);
}
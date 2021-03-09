// 编程模板；包含输入输出重定向功能；
// 编译命令：c++ -std=c++11 example.cc -o out ; ./out; rm out

#include <cstdio>
#include <iostream>

int main(){
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout); // 使用w模式，每次打开文件都清空内容；
    std::string buffer;
    while (std::cin >> buffer)
    {
        std::cout << buffer << " ";
    }
    std::cout << std::endl;
    return 0;
}
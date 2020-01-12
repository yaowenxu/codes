/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-01-12 21:47:14
 * LastEditTime: 2020-01-12 22:12:36
 * Description: 文件描述信息
 */
#include <iostream>
#include <string>

int main(){
    int *a = 0x0;
    int *b = nullptr;
    int c =20;
    b = &c;
    *b = 30;
    int* g;
    a =g; // 指针赋值
    // *b = 20;
    std::cout << "a-addr: " << a << std::endl;
    std::cout << "&c-addr: " << &c << std::endl;
    std::cout << "b-addr: " << b << std::endl;
    long e;
    // std::cin >> std::hex >> e;
    std::cout << "e-value: " << e << std::endl;
    a = (int*)(e);
    std::cout << "*a-value: " << *a << std::endl;
    return 0;
}
/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-01-12 20:39:05
 * LastEditTime: 2020-01-12 21:05:41
 * Description: 文件描述信息
 */
#include <iostream>
class b;
class a{
private:
    int val;
public:
    a(int n){
        val = n;
        std::cout << "a(int n)" << std::endl;
    }
    void print(const a& fri){
        std::cout << fri.val << std::endl;
    }
    void print(){
        std::cout << val << std::endl;
    }
    a(const a& oth){
        val = oth.val;
        std::cout << "val: " << oth.val << std::endl;
        std::cout << "a(const a& oth)" << std::endl;
    }
    friend class d;
};

class d{
private:
    int val;

public:
    d(a other){
        val = other.val;
        std::cout << "d(a other)" << std::endl;
    }
    void print(){
        std::cout << "bval: " << val << std::endl;
    }
};

int main(){
    a b = 10;
    d e = b;
    // b.print();
    // b = 20;
    // a c = b;
    // c.print();
    // std::cout << "main: " << c.val << std::endl;
    return 0;
}
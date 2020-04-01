/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-01 15:54:44
 * LastEditTime: 2020-04-01 16:24:31
 * Description: c++ 复制构造函数的例子
 */

#include <iostream>
using namespace std;

class A{
private:
    int val;
public:
    A(int n){
        cout << "A(int n)" << endl;
        val = n;
    }
    A(const A &other){
        cout << "A(const A &other)" << endl;
        val = other.val;
    }
    void print(){
        cout << val << endl;
    }
};

int main(){
    A a = 20;
    A b = a;
    b.print();
}
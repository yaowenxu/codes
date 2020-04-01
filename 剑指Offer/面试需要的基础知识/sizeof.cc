/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-01 15:38:45
 * LastEditTime: 2020-04-01 15:51:05
 * Description: sizeof 函数功能使用
 */

#include <iostream>
using namespace std;

// 一个空的结构体
class A{
    // 空类型在进行声明的时候，必须在内存中占有一定空间；
};

class B{
public: // 必须要声明public; 因为类中函数默认是私有函数；结构体不需要声明public, 结构里默认类函数为public属性；
    B(){}
    ~B(){} 
};

class C{
public: // 必须要声明public; 因为类中函数默认是私有函数；结构体不需要声明public, 结构里默认类函数为public属性；
    C(){}
    virtual ~C(){} // 声明析构函数为虚函数的时候，会添加一个虚函数表，并在每个实例中添加一个指向虚函数的指针；
};

int main(){
    A a;
    cout << "结构体大小：" << sizeof(a) << endl;
    B b;
    cout << "结构体大小(含有构造函数和析构函数)：" << sizeof(b) << endl;
    C c;
    cout << "结构体大小(虚函数存在，实例中存在一个虚函数表的指针))：" << sizeof(c) << endl;
    return 0;
}
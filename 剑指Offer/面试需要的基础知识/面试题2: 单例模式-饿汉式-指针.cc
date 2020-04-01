/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-01 18:22:25
 * LastEditTime: 2020-04-01 19:54:59
 * Description: c++ 创建单例模式；
 */

#include <iostream>
using namespace std; 

// 这种构造单例的方式，存在着内存泄露的问题；
class Singleton{
private:
    static Singleton *instance;
private:
    Singleton(){
        cout << "单例对象创建！" << endl;
    }
    ~Singleton(){
        cout << "单例对象析构！" << endl;
    }
    Singleton(const Singleton&); // 拷贝操作；
    Singleton& operator=(const Singleton&); // 赋值操作；
public:
    static Singleton* getInstance(){
        return instance;
    }
    static void releaseInstance(){ // 在这里添加了一个释放内存的方法；
        delete instance; // 释放对象的内存；
    }
};

Singleton* Singleton::instance = new Singleton(); //创建单例模式；

int main(){ // 测试单例函数的可用性
    Singleton* p1 = Singleton::getInstance();
    Singleton* p2 = Singleton::getInstance();
    // 此时如果不调用releaseinstance 函数，单例构造的对象就不能释放；因为单例的内存是在堆上创建的；
    Singleton::releaseInstance(); // 使用指定函数来进行析构
    return 0; 
}
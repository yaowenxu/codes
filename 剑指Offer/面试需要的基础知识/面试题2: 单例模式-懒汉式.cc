/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-01 18:22:25
 * LastEditTime: 2020-04-01 22:43:33
 * Description: c++ 创建单例模式；
 * 参考链接：https://blog.csdn.net/cjbct/article/details/79266057 
 * 使用内部静态变量，local-static 进行实现，线程安全；
 */

#include <iostream>
#include <mutex> // 创建互斥变量；
using namespace std; 

// 饿汉式单例模式构建；
class Singleton{
private:
    Singleton(){
        cout << "单例对象创建！" << endl; 
    }
    ~Singleton(){
        cout << "单例对象销毁！" << endl;
    }
    Singleton(const Singleton&); // 拷贝操作；
    Singleton& operator=(const Singleton&); // 赋值操作；
public:
    int val; // 设置数值；
    static Singleton* getInstance(){
        /*
        * C++11规定了local static在多线程条件下的初始化行为，要求编译器保证了内部静态变量的线程安全性。
        * 在C++11标准下，《Effective C++》提出了一种更优雅的单例模式实现，使用函数内的 local static 对象。
        * 这样，只有当第一次访问getInstance()方法时才创建实例。这种方法也被称为Meyers' Singleton。
        * C++0x之后该实现是线程安全的，C++0x之前仍需加锁。
        */
        static Singleton instance; // 需要时再进行创建；
        return &instance; // 返回单例指针；
    }
};

int main(){ // 测试单例函数的可用性
    Singleton *p1 = Singleton::getInstance(); 
    p1->val = 10;
    Singleton *p2 = Singleton::getInstance(); 
    Singleton *p3 = Singleton::getInstance(); // 创建单例模式
    cout << "当前的值：" << p3->val << endl;
    return 0; 
}

/*
non-local static对象（函数外）
C++规定，non-local static 对象的初始化发生在main函数执行之前，也即main函数之前的单线程启动阶段，所以不存在线程安全问题。但C++没有规定多个non-local static 对象的初始化顺序，尤其是来自多个编译单元的non-local static对象，他们的初始化顺序是随机的。
local static 对象（函数内）
对于local static 对象，其初始化发生在控制流第一次执行到该对象的初始化语句时。多个线程的控制流可能同时到达其初始化语句。
在C++11之前，在多线程环境下local static对象的初始化并不是线程安全的。具体表现就是：如果一个线程正在执行local static对象的初始化语句但还没有完成初始化，此时若其它线程也执行到该语句，那么这个线程会认为自己是第一次执行该语句并进入该local static对象的构造函数中。这会造成这个local static对象的重复构造，进而产生内存泄露问题。所以，local static对象在多线程环境下的重复构造问题是需要解决的。
而C++11则在语言规范中解决了这个问题。C++11规定，在一个线程开始local static 对象的初始化后到完成初始化前，其他线程执行到这个local static对象的初始化语句就会等待，直到该local static 对象初始化完成。
*/
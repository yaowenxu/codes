/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-01 18:22:25
 * LastEditTime: 2020-04-01 21:53:09
 * Description: c++ 创建单例模式；
 * 参考链接：https://blog.csdn.net/cjbct/article/details/79266057 
 */

#include <iostream> 
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
    static Singleton instance;
public:
    static Singleton* getInstance(){
        return &instance; // 返回单例指针；
    }
};
Singleton Singleton::instance; // 创建单例实例；

int main(){ // 测试单例函数的可用性
    Singleton *p1 = Singleton::getInstance();
    Singleton *p2 = Singleton::getInstance();
    Singleton *p3 = Singleton::getInstance(); // 创建单例模式
    return 0; 
}
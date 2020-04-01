/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu 
 * Organization: 北航系统结构研究所 
 * Date: 2020-04-01 18:22:25 
 * LastEditTime: 2020-04-01 22:39:40
 * Description: c++ 创建单例模式；
 * 参考链接：https://blog.csdn.net/cjbct/article/details/79266057 
 * https://zhuanlan.zhihu.com/p/37469260
 * DCL: Double-Checked Locking Pattern; 使用 mutex 线程安全；
 */

#include <iostream> 
#include <mutex>
using namespace std; 

mutex gmutex;

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
    static Singleton *instance; // 需要时再进行创建；
public:
    static Singleton* getInstance(){
        if (instance == nullptr)
        {
            lock_guard<mutex> lock(gmutex); // 基于作用域加锁，超出作用域自动调用析构函数解锁；
            if (instance == nullptr)
            {
                // 声明单例模式
                instance = new Singleton();
            }
        }
        return instance; // 返回单例指针；
    }
    static void releaseInstance(){
        lock_guard<mutex> lock(gmutex);
        if (instance != nullptr)
        {
            delete instance; // 进行删除指针；
        }   
    }
};

Singleton* Singleton::instance = nullptr;

int main(){ // 测试单例函数的可用性
    Singleton *p1 = Singleton::getInstance();
    Singleton *p2 = Singleton::getInstance();
    Singleton *p3 = Singleton::getInstance(); // 创建单例模式
    Singleton::releaseInstance();
    return 0; 
}
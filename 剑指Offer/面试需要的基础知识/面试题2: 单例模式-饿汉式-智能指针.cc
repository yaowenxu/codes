/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-01 18:22:25
 * LastEditTime: 2020-04-01 19:47:24
 * Description: c++ 创建单例模式-使用智能指针创建；使用智能指针动态构建和删除对象；
 */

#include <iostream>
#include <memory> // 引入c++内存模块；
using namespace std; 

class Singleton{
private:
    Singleton(){
        cout << "单例对象创建!" << endl;
    }
    Singleton(const Singleton&); // 拷贝操作；
    Singleton& operator=(const Singleton&); // 赋值操作；
    ~Singleton(){
        cout << "单例对象销毁!" << endl;
    }
    static shared_ptr<Singleton> instance; // 创建智能指针
public:
    int val;
    static Singleton* getInstance(){
        return instance.get();
    }
    static void Destory(Singleton* s){
        cout << "Destory单例对象！" << endl; // 调用删除函数
        if (s!=nullptr)
        {
            delete s;
        }
    }
};

shared_ptr<Singleton> Singleton::instance(new Singleton(), Singleton::Destory); //删除时，销毁单例对象；
int main(){ // 测试单例函数的可用性
    Singleton *p = Singleton::getInstance(); // 返回该类的单例对象；
    p->val = 10;
    p = Singleton::getInstance(); // 返回该类的单例对象；
    cout << p->val << endl;
    return 0; 
}
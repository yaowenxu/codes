/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-01 18:22:25
 * LastEditTime: 2020-04-01 19:50:39
 * Description: c++ 创建单例模式；饿汉式；此种方式线程安全
 */

#include <iostream>
using namespace std; 

class Singleton{
private:
    static Singleton *instance;
    Singleton(){}
    ~Singleton(){
        cout << "本身析构！" << endl;
    }
    Singleton(const Singleton&); // 拷贝操作；
    Singleton& operator=(const Singleton&); // 赋值操作；
private:
    // 使用静态内部类，进行自动释放；
    class Deletor{
        public:
            Deletor(){
                cout << "内部类创建！" << endl;
            }
            ~Deletor(){
                if(instance != nullptr){
                    cout << "内部类析构！" << endl;
                    delete instance; // 删除instance 指针，指向的内存；
                    // 在此处，通过内部类来进行创建和进行析构；
                    instance = nullptr; // 设置此时的指针为空；
                }
            }
    };
    static Deletor deletor;
public:
    int val;
    static Singleton* getInstance(){
        return instance;
    }
};

Singleton* Singleton::instance = new Singleton(); //进行初始化单例指针；
Singleton::Deletor Singleton::deletor; // 此处进行生命内部类；

int main(){ // 测试单例函数的可用性
    Singleton *p = Singleton::getInstance(); // 返回该类的单例对象；
    p->val = 10;
    p = Singleton::getInstance(); // 返回该类的单例对象；
    cout << p->val << endl;
    return 0; 
}
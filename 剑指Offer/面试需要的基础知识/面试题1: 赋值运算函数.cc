/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-01 16:39:52
 * LastEditTime: 2020-04-01 17:30:26
 * Description: 赋值预算函数，注意赋值函数的编写的形式；
 */
#include <iostream> 
#include <string> 
#include <cstring> 
using namespace std; 

class A{
public:
    int val;
    char* pstr;
    A(int n){ val = n; pstr = nullptr;}
    ~A(){
        if (pstr != nullptr)
        {
            delete[] pstr; //进行删除该指针指向的内存；
        }
    }

    A(const A &a){
        val =a.val;
        if(a.pstr != nullptr){
            pstr = nullptr;
            pstr = new char[strlen(a.pstr)+1]; // 未被了异常安全性原则，在内存不够的时候，可能会报错；
            strcpy(pstr, a.pstr); // 进行拷贝字符串；
        }
    }

    A(char* s){
        // 判断输入是否存在空指针情况；
        if (s == nullptr){
            pstr = new char[1];
            pstr[0] = '\0'; // 设置字符串结尾
        } else{
            pstr = new char[strlen(s)+1];
            strcpy(pstr, s);  
        }
    }
    void setpstr(const char* str){
        pstr = new char[strlen(str)+1];
        strcpy(pstr, str);
    }
    
    A& operator=(const A& a){
        if (this == &a)
        {
            return *this;
        }
        
        val = a.val; // "进行对赋值语句的操作"
        // 判断是否对字符串进行修改
        if (a.pstr != nullptr)
        {
            A tmp(a); // 通过这种内存交换的操作，可以体现出面试者对代码异常有深刻的理解；
            char* ptmp =  tmp.pstr;
            tmp.pstr = pstr;
            pstr = ptmp; // 进行交换内存；
        }
        return *this;
    }
    
    void print(){
        cout << val << endl;
        if (pstr != nullptr)
        {
            cout << pstr << endl;
        }
    }
};

int main(){
    A a = 10;
    string str = "c++ lang";
    a.setpstr(str.c_str());
    A b = 100;
    string javastr = "java lang";
    b.setpstr(javastr.c_str()); // 针对于javastr的设置；
    A c = 1000;
    a = b = c;
    a = a;
    a.print();
}
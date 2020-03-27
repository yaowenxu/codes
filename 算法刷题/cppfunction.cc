/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-02-21 18:44:38
 * LastEditTime: 2020-02-22 13:29:09
 * Description: 文件描述信息
 */

class Student
{
private:
    /* data */
public:
    Student(/* args */);
    ~Student();
    void study();
};

Student::Student(/* args */) = default;

Student::~Student() = default;

class b{};

class a{
    public:
    b c;
    void a_func();
    protected:
    private:
};

class test{
public:
    int a;
    int b;
public:
    test(int a, int b):a(a),b(b){}
};

#include <iostream>
using namespace std;

int main(){
    a d;
    Student stu;
    //stu.study();
    test t(1,2);
    test t2{3,4};
    cout << t2.a;
    return 0;
}
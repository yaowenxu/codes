/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-01-12 21:09:24
 * LastEditTime: 2020-01-12 21:35:51
 * Description: 文件描述信息
 */
#include <iostream>
#include <string>

class cmystring{
public:
    cmystring(const std::string data = "data-init"){
        str = data;
        // std::cout << "string by init" << std::endl;
    };

    cmystring(const cmystring& str){
        this->str = str.str;
    };
    ~cmystring(){
        
    };

    cmystring& operator= (const cmystring& othstring){
        str = othstring.str;
        std::cout << "operator reload: " << this << std::endl;
        return *this;
    }

    void print(){
        std::cout << "cmystring-print: " << str << std::endl;
    }
    
private:
    std::string str;
};

int main (){
    // cmystring a;
    cmystring a = std::string("a");
    cmystring c = std::string("c");
    a.print();
    c.print();
    // std::cout << "sizeof: " << sizeof(a) << std::endl;
    cmystring b;
    b.print();
    b = a = c;
    // b = c;
    b.print();
    a.print();
    return 0;
}
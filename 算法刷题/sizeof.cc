/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-01-12 20:11:27
 * LastEditTime: 2020-01-12 20:33:30
 * Description: 文件描述信息
 */
#include <cstdio>
#include <iostream>

struct foo
{
    /* data */
};

class bar{
public:
    bar(){
        std::cout << "bar" << std::endl;
    }
    virtual ~bar(){
        std::cout << "~bar" << std::endl;
        std::cout << "~~bar" << std::endl;
    }
};

int main(int argc, char* argv[]){
    bar a;
    std::cout << "类型的大小: " << sizeof(a) << std::endl;
    return 0;
}
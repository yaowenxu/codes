/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-01-13 13:11:17
 * LastEditTime: 2020-01-13 13:13:06
 * Description: 文件描述信息
 */
#include <iostream>

int main(){
    int a[5] = {1,2,3,4,5};
    int *b = a;
    std::cout << "SizeofArray: " << sizeof(b) << std::endl;
    return 0;
}
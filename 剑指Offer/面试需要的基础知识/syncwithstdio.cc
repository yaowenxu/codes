/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-02 12:52:50
 * LastEditTime: 2020-04-02 12:54:17
 * Description: 和stdio 同步
 */

#include <iostream>
#include <cstdio>
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout << "a\n";
    std::printf("b\n");
    std::cout << "c\n";
}
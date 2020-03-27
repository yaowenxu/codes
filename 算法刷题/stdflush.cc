/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-02-21 14:34:26
 * LastEditTime: 2020-02-21 17:14:00
 * Description: 文件描述信息
 */

#include <iostream>
#include <chrono>
template<typename Diff>
void log_progress(Diff d)
{
    std::cout << "..("
              << std::chrono::duration_cast<std::chrono::milliseconds>(d).count()
              << " ms).." << std::flush;//<< std::endl;//std::flush;
}
int main()
{
    volatile int sink=0;
 
    auto t1 = std::chrono::high_resolution_clock::now();
    for(int j=0; j<5; ++j)
    {
        for(int n=0; n<10000; ++n)
            for(int m=0; m<20000; ++m)
                sink += m*n; // do some work
        auto now = std::chrono::high_resolution_clock::now();
        log_progress(now - t1);
    }
    std::cout << '\n';
}
/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-02-21 17:47:15
 * LastEditTime: 2020-02-21 19:47:31
 * Description: 文件描述信息
 */

#include <pthread.h>
#include <iostream>
#include <assert.h>
using namespace std;

int func(int i){return i+100;};
int func(char c) = delete;

int main(){
    pthread_t tid;
    tid = pthread_self();
    cout << strerror(pthread_join(tid, nullptr)) << endl;
    // assert("pthread"!=0);
    cout << EINVAL << endl;
    cout << ESRCH << endl;
    cout << EDEADLK << endl; // 自己join 自己死锁了；
    cout.flush();
    cout<< func(1);
    cout.flush();
    return 0;
}
/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-02-24 18:04:53
 * LastEditTime: 2020-02-24 21:26:09
 * Description: 文件描述信息
 */

#include <iostream>
using namespace std;

int main(){
    assert(true);
    bool e = true && true;
    cout << "Assert finish! " << endl;
    cout << e << endl;
    cout << __FILE__ << endl;
    cout << __LINE__ << endl;
    cout << __DATE__ << endl;
    // cout << __STDC__ << endl;
    cout << __FUNCTION__ << endl;
    cout << __TIME__ << endl;
    cout << __cplusplus << endl;
    return 0;
}
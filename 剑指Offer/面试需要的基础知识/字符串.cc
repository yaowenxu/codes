/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-02 17:51:48
 * LastEditTime: 2020-04-02 19:15:01
 * Description: 字符串性质熟悉；
 */

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(){
    char str[11];
    strcpy(str, "0123456789"); // 拷贝字符串；
    cout << str << endl;
    string s = "hello";
    s.resize(9);
    s[5] = 'x';
    s[6] = '\0';
    cout << s.size() << endl;
    return 0;
}
/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2019-08-27 09:28:25
 * LastEditTime: 2019-08-27 10:01:59
 * Description: IP 地址无效化 leetcode
 */
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        ostringstream osstr;
        for (auto s : address){
            if(s >='0'&& s <='9'){
                osstr << s;
            }
            if(s=='.'){
                osstr << "[.]";
            }
        }
        return osstr.str();
    }
};

int main(int argc, char* argv[]){
    string address = "255.100.50.0";
    Solution solver;
    cout << solver.defangIPaddr(address) << endl; // 转换，并输出结果
    return 0;
}


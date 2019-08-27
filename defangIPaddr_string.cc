/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2019-08-27 09:28:25
 * LastEditTime: 2019-08-27 10:09:23
 * Description: IP 地址无效化 leetcode
 */
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string result = "";
        for (auto s : address){
            if(s=='.'){
                result += "[.]";
            }else{
                result += s;
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]){
    string address = "255.100.50.0";
    Solution solver;
    cout << solver.defangIPaddr(address) << endl; // 转换，并输出结果
    return 0;
}


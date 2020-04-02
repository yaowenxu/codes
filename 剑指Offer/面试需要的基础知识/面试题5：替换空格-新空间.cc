/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-02 18:52:23
 * LastEditTime: 2020-04-02 19:11:46
 * Description: 替换空格, 模拟数据进行原字符串替换操作；
 */
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string o = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                o+= "%20";
            }
            else{
                o+= s[i];
            }
        }
        return o;
    }
};
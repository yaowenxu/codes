/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-02 18:52:23
 * LastEditTime: 2020-04-02 19:24:54
 * Description: 替换空格, 模拟数据进行原字符串替换操作；
 */
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int oldsize = 0;
        int newsize = 0;
        // 确定新字符串的长度；
        for (int i = 0; i < s.size(); i++)
        {
            oldsize++;
            newsize++;
            if (s[i] == ' ')
            {
                newsize += 2; // 增大字符串大小；
            }
        }
        s.resize(newsize);
        // 复制字符串；
        int p1 = oldsize-1; int p2= newsize-1;
        while (p1!=p2)
        {
            if (s[p1]!=' ')
            {
                s[p2] =  s[p1];
                p1--; p2--;
            }else{
                s[p2--] = '0';
                s[p2--] = '2';
                s[p2--] = '%';
                p1--;
            }
        }
        return s;
    }
};
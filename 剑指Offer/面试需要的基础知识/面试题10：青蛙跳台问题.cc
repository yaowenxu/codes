/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-04 12:02:56
 * LastEditTime: 2020-04-04 12:10:04
 * Description: 青蛙跳台问题
 */

class Solution {
public:
    int numWays(int n) {
        if (n==0)
        {
            return 1;
        }
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        // 初始化变量参数；
        int n1 =1;
        int n2 = 2;
        int n3 = 0;
        for (int i = 3; i <= n; i++)
        {
            n3 = (n2+n1)%1000000007;
            n1 = n2;
            n2 = n3;
        }
        return n3;
    }
};
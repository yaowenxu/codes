/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-04 00:44:01
 * LastEditTime: 2020-04-04 00:56:25
 * Description: 斐波那契问题 非递归
 */

// 使用循环求解；
class Solution {
public:
    int fib(int n) {
        int n0 = 0;
        int n1 = 1;
        int n2 = 0;
        if (n==0)
        {
            return n0;
        }
        if (n==1)
        {
            return n1;
        }
        for (int i = 2; i <=n; i++)
        {
            n2 = (n1 + n0)%(1000000007);
            n0 = n1;
            n1 = n2;
        }
        return n2;
    }
};
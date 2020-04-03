/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-04 00:40:54
 * LastEditTime: 2020-04-04 00:43:26
 * Description: 斐波那契数列问题；- 递归求解；
 */

class Solution {
public:
    int fib(int n) {
        if (n==0)
        {
            return 0;
        }
        if (n==1)
        {
            return 1;
        }
        return fib(n-1)+ fib(n-2);
    }
};
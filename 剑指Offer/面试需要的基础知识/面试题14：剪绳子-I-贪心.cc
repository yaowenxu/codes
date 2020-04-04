/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-04 21:34:45
 * LastEditTime: 2020-04-04 23:37:31
 * Description: 剪绳子-贪心；使用贪心策略来进行求解；
 */
#include <cmath>
class Solution {
public:
    int cuttingRope(int n) {
        if (n == 2)
        {
            return 1;
        }
        if (n == 3)
        {
            return 2;
        }
        int timeof3 = n/3;
        if (n-3*timeof3 == 1)
        {
            timeof3 -= 1;
        }
        int timeof2 = (n-3*timeof3)/2;
        return (int)(pow(3, timeof3))* (int)(pow(2, timeof2)); // 返回最后的结果
    }
};
/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-05 11:47:04
 * LastEditTime: 2020-04-05 12:17:49
 * Description: 剪绳子-II, 大数；不能使用 pow处理大数; 不能使用dp; 可以使用贪心求解；
 */
#include <cmath>
class Solution {
public:
    int cuttingRope(int n) {
        if (n==2)
        {
            return 1;
        }
        if (n==3)
        {
            return 2;
        }
        
        int timeof3 = n/3;
        if ((n-timeof3*3)==1)
        {
            timeof3--;
        }
        int timeof2 = (n-timeof3*3)/2;
        long int r2 =  int(pow(2, timeof2)); // 返回2的结果
        long int r3 = 1;
        for (size_t i = 0; i < timeof3; i++)
        {
            r3 = (r3*3)%1000000007;
        }
        return int((r3*r2)%1000000007);
    }
};
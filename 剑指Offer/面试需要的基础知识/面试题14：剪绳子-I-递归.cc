/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-04 21:34:45
 * LastEditTime: 2020-04-04 23:05:37
 * Description: 剪绳子-递归; 这种情况下超时了；毫无疑问的情况下超时；自顶向下；
 */

class Solution {
public:
    // 切的情况下，最大值；
    int f(int n){
        if (n==1) // 1不切；
        {
            return 1;
        }
        if (n==2)  // 2不切；
        {
            return 2;
        }
        if (n==3) // 3不切；
        {
            return 3; 
        }
        // 对于没切一刀都要讨论4个子问题；前后办部分都不切；前半部分切，后半部分不切；前半部分不切，后半部分切；前后半部分都切；
        // 从4开始，切的情况下大于不切的情况；所以之后一直讨论切的情况；
        int max = 0;
        for (int i = 1; i <= n/2; i++)
        {
            if (f(i)*f(n-i) >= max)
            {
                max = f(i)*f(n-i);
            }
        }
        return max;
    }

    int cuttingRope(int n){
        if (n==2) // 2切
        {
            return 1;
        }
        if (n==3) // 3切
        {
            return 2;
        }
        return f(n);
    }
};
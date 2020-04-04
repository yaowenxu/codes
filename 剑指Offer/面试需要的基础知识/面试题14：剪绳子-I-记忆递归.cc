/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-04 21:34:45
 * LastEditTime: 2020-04-04 23:12:45
 * Description: 剪绳子-递归; 利用带有记忆的递归，减少重复计算；
 */

class Solution {
public:
    int p[59]; //利用递归函数
    // 切的情况下，最大值；
    int f(int n){
        if (n==1) // 1不切；
        {
            p[1] = 1;
            return 1;
        }
        if (n==2)  // 2不切；
        {
            p[2] = 2;
            return 2;
        }
        if (n==3) // 3不切；
        {
            p[3] = 3;
            return 3; 
        }
        if (p[n]!= 0)
        {
            return p[n]; // 利用查表加快求值；
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
        p[n] = max;
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
/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-04 21:34:45
 * LastEditTime: 2020-04-04 23:22:21
 * Description: 剪绳子-dp; 使用数组自底向上求解；
 */

class Solution {
public:
    int p[59]; // 子弟

    int cuttingRope(int n){
        if (n==2) // 2切
        {
            return 1;
        }
        
        if (n==3) // 3切
        {
            return 2;
        }
        
        p[0] = 0;
        p[1] = 1;
        p[2] = 2;
        p[3] = 3;
        for (int i = 4; i <= n; i++)
        {
            int max = 0;
            for (int j = 1; j <= i/2; j++)
            {
                if (p[j]*p[i-j] >= max)
                {
                    max = p[j]*p[i-j];
                }
            }
            p[i] = max; 
        }
        return p[n];
    }
};
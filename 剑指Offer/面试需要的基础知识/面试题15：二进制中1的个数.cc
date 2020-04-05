/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-05 12:20:49
 * LastEditTime: 2020-04-05 12:34:45
 * Description: 判断二进制中1的个数，并输出；利用 flag = 1, 与原数与，并移位；判断每一位是否为1；
 */
#define uint32_t int
// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
//         uint32_t flag = 1;
//         int cnt = 0;
//         while (flag)
//         {
//             if ((n&flag))
//             {
//                 cnt++; // 增加1的个数；
//             }
//             flag <<= 1; // flag 右移一玮；
//         }
//         return cnt; // 返回 cnt 的值；
//     }
// };

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n)
        {
            cnt ++;
            n = (n-1)&n;
        }
        return cnt;
    }
};
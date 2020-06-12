#include <iostream>
using namespace std;

class Solution {
public:
    // 利用了减治的思想，来进行加快数据处理；
    double calpow(double base, long int exp){
        if (exp == 1)
        {
            return base;
        }
        if (exp == 0){
            return 1;
        }
        double result =  calpow(base, exp >> 1);
        result *= result;
        if (exp & 0x1 == 1)
        {
            result *= base;
        }
        return result;
    }

    double myPow(double x, int n) {
        double res = x;
        if(x==0){
            return 0;
        }
        if (n==0)
        {
            return 1;
        }
        long int cnt = n;
        if(cnt < 0){
            cnt = 0-cnt;
        }
        res = calpow(x, cnt);
        if (n < 0)
        {
            res = 1/res;
        }
        return res;
    }
};

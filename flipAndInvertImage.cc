/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2019-08-28 20:05:54
 * LastEditTime: 2019-08-28 21:20:35
 * Description: 反转图像 leetcode 
 */

#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int vecsize = A[0].size();
        int swaptmp =  0;
        for(int j = 0; j < A.size(); j++){
            for(int i = 0; i < (vecsize+1)/2; i++){
                swaptmp = A[j][vecsize-i-1];
                A[j][vecsize-i-1] = !A[j][i];
                A[j][i] =  !swaptmp;
            }
            // for(int i = 0; i < vecsize; i++){
            //     A[j][i] =  !A[j][i]; // 进行图像反转
            // }
        }
    }
};

int main(){


    return 0;
}
/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-02 16:07:38
 * LastEditTime: 2020-04-02 16:59:34
 * Description: 二维数组中的查找；
 * https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/ 
 */

/*
[[1,4,7,11,15],
[2,5,8,12,19],
[3,6,9,16,22],
[10,13,14,17,24],
[18,21,23,26,30]]
20
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        std::ios::sync_with_stdio(false);
        if (matrix.empty()) return false;
        int row = matrix.size();
        int col = matrix[0].size();
        int i = 0; int j = col -1;
        while (i < row && j >=0 )
        {
            if(matrix[i][j] ==  target){
                return true;
            }
            if (matrix[i][j] < target)
            {
                i++;
            }
            else if (matrix[i][j] > target){
                j--;
            }
        }
        return false;
    }
};
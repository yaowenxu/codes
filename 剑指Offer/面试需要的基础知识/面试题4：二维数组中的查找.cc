/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-02 16:07:38
 * LastEditTime: 2020-04-02 16:45:56
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
using namespace std;
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int sizei = matrix.size();
        if (sizei == 0)
        {
            return false;
        }
        int sizej = matrix[0].size();
        if (sizej == 0)
        {
            return false;
        }
        
        int i = 0; int j =  sizej-1;
        while(true){
            while (j >= 0 && matrix[i][j] > target)
            {
                j--;
            }
            // 判断是否越界
            if (j < 0)
            {
                return false;
            }
            while ( i < sizei && matrix[i][j] < target)
            {
                i++;
            }
            // 判断是否越界
            if (i >= sizei)
            {
                return false;
            }
            // 判断是否达到目标
            if(matrix[i][j] == target){
                return true;
            }
        }
    }
};
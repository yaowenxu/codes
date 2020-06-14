// 顺时针打印矩阵
#include <vector>
using namespace std;
// 顺时针打印矩阵；
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res; // 最终的返回数组；
        int i = matrix.size(); // 获取矩阵的行数；
        if (i == 0)
        {
            return res;
        }
        int j =  matrix[0].size();
        if (j == 0)
        {
            return res; // 当矩阵j = 0 的时候；
        }
        int sum = i*j;
        // 进行打印 i 行， j列的矩阵；
        int left = 0; int right = j-1;
        int top = 0; int bottom = i-1; // 矩阵的上部和底部；
        while (true) // 循环一圈；
        {
            int s_size = res.size();
            for (int j = left; j <=right; j++)
            {
                res.push_back(matrix[top][j]);
            }
            top++;
            if (res.size() == sum) break;
            for (int i = top; i <= bottom; i++)
            {
                res.push_back(matrix[i][right]);
            }
            right--;
            if (res.size() == sum) break;
            for (int j = right; j >= left; j--)
            {
                res.push_back(matrix[bottom][j]);
            }
            bottom--;
            if (res.size() == sum) break;
            for (int i = bottom; i >= top; i--)
            {
                res.push_back(matrix[i][left]);
            }
            left++;
            if (res.size() == sum) break;
        }
        return res; 
    } 
};
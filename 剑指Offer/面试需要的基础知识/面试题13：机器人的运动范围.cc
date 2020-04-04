/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-04 19:35:55
 * LastEditTime: 2020-04-04 20:59:18
 * Description: 机器人的运动范围；利用回溯方法来进行搜索；知道达到边界；
 */
#include <vector>
#include <iostream>
using namespace std; 
class Solution {
public:
    int m;
    int n;
    int k;
    int sumit(int i, int j){
        int sumi = 0;
        while (i/10 != 0)
        {
            sumi += i%10;
            i /= 10; // 判断其中的值；
        }
        sumi += i;
        int sumj = 0;
        while (j/10 != 0)
        {
            sumj += j%10;
            j /= 10; // 判断其中的值；
        }
        sumj += j;
        return sumi+sumj;
    }

    int findcount(vector<vector<bool>>& vis, int i, int j){
        if (sumit(i,j) > k)
        {
            return 0;
        }
        int cnt = 1;
        vis[i][j] = true; 
        if (i-1>=0 && !vis[i-1][j])
        {
            cnt += findcount(vis, i-1, j); // 搜上；
        }
        
        if (j-1>=0 && !vis[i][j-1])
        {
            cnt += findcount(vis, i, j-1); // 搜左；
        }

        if (i+1 < m && !vis[i+1][j])
        {
            cnt += findcount(vis, i+1, j); // 搜下；
        }

        if (j+1 < n && !vis[i][j+1])
        {
            cnt += findcount(vis, i, j+1); // 搜右；
        }
        //vis[i][j] = false; // 此处不进行标记；注意标记的意义；
        return cnt;
    }
    int movingCount(int mm, int nn, int kk) {
        m = mm;
        n = nn;
        k = kk;
        // 轨迹数组；
        vector<vector<bool>> visit(m, vector<bool>(n,false)); // 创建标记数组
        return findcount(visit, 0, 0); // 从零开始进行搜索；
    }
};
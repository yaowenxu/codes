/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2019-08-26 14:42:17
 * LastEditTime: 2019-08-26 16:15:14
 * Description: 计算两个数字的和
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution{
    public:
    vector<int> twosum(vector<int>& sums, int target){
        vector<int> ret;
        for(int i = 0; i < sums.size(); i++){
            for(int j = i+1; j  < sums.size(); j++){
                if(i == j){
                    continue;
                }
                if (sums[i]+sums[j] == target){
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        return ret; // 返回数组中的值
    }
};

int main(int argc, char* argv[]){
    vector<int> vec = {2, 7, 11, 15};
    int target = 9;
    Solution solve;
    vector<int> ret =  solve.twosum(vec, target);
    cout << ret[0] << "," << ret[1] << endl; // 返回最终结果
    return 0;
}
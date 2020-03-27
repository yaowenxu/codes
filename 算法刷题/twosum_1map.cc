/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2019-08-26 14:42:17
 * LastEditTime: 2019-08-26 16:28:06
 * Description: 计算两个数字的和
 */

#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution{
    public:
    vector<int> twosum(vector<int>& nums, int target){
        vector<int> ret;
        map<int,int> numsmap;
        for(int i = 0; i < nums.size(); i++){
            int j = target-nums[i];
            if (numsmap.find(j) != numsmap.end()){
                ret.push_back(numsmap[j]);
                ret.push_back(i);
                return ret;
            }
            numsmap[nums[i]] = i;
        }
        return ret; // 返回数组中的值
    }
};

int main(int argc, char* argv[]){
    vector<int> vec = {2, 7, 11, 15};
    int target = 9;
    // vector<int> vec = {3, 2, 4};
    // int target = 6;
    Solution solve;
    vector<int> ret =  solve.twosum(vec, target);
    cout << ret[0] << "," << ret[1] << endl; // 返回最终结果
    return 0;
}
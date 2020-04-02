/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-02 12:09:52
 * LastEditTime: 2020-04-02 13:13:40
 * Description: 面试题3，找出数组中重复的数字
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// class Solution {
// public:
//     int findRepeatNumber(vector<int>& nums) {
//         int size =  nums.size(); // 数字都在0-n-1范围内；
//         vector<bool> vis(size, false); // 初始化数组；
//         for(int i = 0; i < size; i++){
//             if (vis[nums[i]])
//             {
//                 return nums[i];
//             }
//             vis[nums[i]] = true;
//         }
//         return 0;
//     }
// };

// 通过数组归位来进行求解；
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        std::ios::sync_with_stdio(false); //
        for (int i = 0; i < nums.size(); i++)
        {
            while(nums[i]!=i){
                int index =  nums[i];
                if(nums[index] == index){
                    return index;
                } else{
                    swap(nums[i], nums[index]);
                }
            }
        }
        return -1;
    }
};

int main(){
    // int arr[7] = {2,3,1,0,2,5,3};
    int arr[16] = {0, 1, 2, 3, 4, 11, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    vector<int> vec(arr, arr+16);
    Solution s;
    cout << s.findRepeatNumber(vec) << endl; // 返回测试结果；
}
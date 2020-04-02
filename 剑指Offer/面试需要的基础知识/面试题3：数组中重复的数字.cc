/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-02 12:09:52
 * LastEditTime: 2020-04-02 15:25:46
 * Description: 面试题3，找出数组中重复的数字
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 通过使用数组作为哈希表的方法来计算；
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

// 通过二分查找的方法来求解；
// class Solution {
// public:
//     int rangeCount(vector<int> &nums, int start, int end){
//         int count = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (nums[i] >= start && nums[i] <= end)
//             {
//                 // 在范围之中；
//                 count++;
//             }
//         }
//         return count++;
//     }
//     int findRepeatNumber(vector<int>& nums) {
//         int start = 0;
//         int end =  nums.size()-1;
//         while (end >= start)
//         {
//             int mid = (start+end)/2; // 找到数组中的中间值
//             // cout << start << " " << mid << " " << end << endl;
//             int cnt = rangeCount(nums, start, mid);
//             int cnt2 = rangeCount(nums, mid+1, end);
//             // cout << cnt << endl;
//             if (start == end)
//             {
//                 if (cnt > 1)
//                 {
//                     return start;
//                 }else
//                 {
//                     break;
//                 }
//             }
//             int size = mid-start+1;
//             if ( cnt > size)
//             {
//                 end = mid;
//             }else{
//                 start = mid+1;
//             }
//         }
//         return -1;
//     }
// };

int main(){
    // int arr[7] = {2,3,1,0,2,5,3};
    // [0, 1, 2, 0, 4, 5, 6, 7, 8, 9]
    // int arr[10] = {0, 1, 2, 0, 4, 5, 6, 7, 8, 9};
    int arr[16] = {0, 1, 2, 3, 4, 11, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    vector<int> vec(arr, arr+16);
    Solution s;
    cout << s.findRepeatNumber(vec) << endl; // 返回测试结果；
}
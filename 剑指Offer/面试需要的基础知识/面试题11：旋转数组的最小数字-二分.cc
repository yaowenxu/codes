/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-04 12:53:56
 * LastEditTime: 2020-04-04 16:11:18
 * Description: 旋转数组的最小数字
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findmid(vector<int> &nums, int start, int end){
        int mid =  (start+end)/2; // 求出中间数值；
        if (end-start == 1)
        {
            return nums[end];
        }
        int res = -1;
        // 当出现起始值和结尾值，以及中间值相等的时候，
        if (nums[start]==nums[end]&& nums[start]==nums[mid])
        {
            int min = nums[start];
            for (int i = start; i <= end; i++)
            {
                if (nums[i] <= min)
                {
                    min = nums[i];
                }
            }
            return min; // 返回最小值；
        }
        if (nums[mid] >= nums[start])
        {
            res = findmid(nums, mid, end); // 进行缩小范围；
        }else if (nums[mid] <= nums[end])
        {   
            res = findmid(nums, start, mid); // 进行缩小范围;
        }
        return res;
    }

    int minArray(vector<int> &numbers) {
        if (numbers.size()==0)
        {
            return -1; // -1 表示没找到值；
        }
        if (numbers[numbers.size()-1] > numbers[0])
        {
            return numbers[0];
        }
        int res = findmid(numbers, 0, numbers.size()-1); //找到数组中的最小值；
        return res; // 返回数组中的最小值；
    }
};
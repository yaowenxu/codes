#include <vector>
using namespace std;
// 进行一次扫描，即完成奇偶数字的交换；
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int len = nums.size();
        int j = 0; int o = len -1;
        while (j <= o)
        {
            if ((nums[j]&0x1) == 0)
            {
                while (j < o && (nums[o]&0x1) == 0)
                {
                    o--;
                }
                int tmp =  nums[j];
                nums[j] = nums[o];
                nums[o] = tmp;
            }
            j++;
        }
        return nums;
    }
};
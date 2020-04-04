/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-04 12:46:40
 * LastEditTime: 2020-04-04 12:48:30
 * Description: 旋转数组的最小数字
 */
#include <vector>
using namespace std;
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        if(n == 0){
            return -1;
        }
        if(n == 1){
            return numbers[0];
        }
        int min = numbers[0];
        for(int i = 1; i < numbers.size(); i++){
            if( numbers[i-1] <= numbers[i] ){
                continue;
            }else{
                return numbers[i];
            }
        }
        return min;
    }
};
/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2019-08-26 16:38:34
 * LastEditTime: 2019-08-26 16:49:10
 * Description: numJewelsInStones 771 leetcode
 */

#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> jset;
        for(int i = 0; i < J.size(); i++){
            jset.insert(J[i]);
        }
        int count = 0;
        for(int i = 0; i < S.size(); i++){
            if(jset.find(S[i])!=jset.end()){
                count++; // 增加寻找到的数量
            }
        }
        return count;
    }
};

int main(int argc, char* argv[]){
    string J = "aA";
    string S = "aAAbbbb";
    Solution solve;
    cout << solve.numJewelsInStones(J, S) << endl; // 输出宝石数量
    return 0;
}
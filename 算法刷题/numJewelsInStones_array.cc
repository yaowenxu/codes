/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2019-08-26 16:38:34
 * LastEditTime: 2019-08-26 17:28:47
 * Description: numJewelsInStones 771 leetcode
 */

#include <iostream>
#include <set>
using namespace std;
class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        bool jset[52];
        memset(jset, 0, sizeof(bool) * 52);
        for (auto j : J)
        {
            if (j < 'a')
            {
                jset[j - 'A'] = true;
            }
            else
            {
                jset[j - 'a' + 26] = true;
            }
        }
        int count = 0;
        for (auto s : S)
        {
            if (s < 'a' && jset[s - 'A'])
            {
                count++;
            }
            else if (s >= 'a')
            {
                if (jset[(s - 'a') + 26])
                {
                    count++;
                }
            }
        }
        return count;
    }
};

int main(int argc, char *argv[])
{
    string J = "aA";
    string S = "aAAbbbb";
    Solution solve;
    cout << solve.numJewelsInStones(J, S) << endl; // 输出宝石数量
    return 0;
}
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        int max = 9;
        while (--n)
        {
            max = max*10+9;
        }
        int cnt = 0;
        while (max--)
        {
            cnt++;
            res.push_back(cnt);
        }
        return res;
    }
};
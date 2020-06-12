//注意：本道题还可以用有限状态机的方法来进行求解！画出状态转移图；针对每个字符来进行状态转移；
#include <string>
using namespace std;
class Solution {
public:
    bool scanInt(string s, int *index){
        // while (s[*index]==' ')
        // {
        //     ++(*index);
        // }
        if (s[*index]=='+'|| s[*index] == '-')
        {
            ++(*index);
        }
        return scanUint(s, index);
    }
    // 进行识别字符串；
    bool scanUint(string s, int *index){
        int count = 0;
        while ((s[*index]!='\0'&& s[*index]>='0' && s[*index] <= '9') )//|| s[*index] == ' ')
        {
            // if(s[*index] != ' '){
            count++;
            // }
            ++(*index);
        }
        return count > 0;
    }
    bool isNumber(string s) {
        if (s.empty())
        {
            return false;
        }
        int index = 0;
        while (s[index]==' ')
        {
            ++(index);
        }
        bool numeric =  scanInt(s, &index);
        if (s[index]=='.')
        {
            ++index;
            numeric = scanUint(s, &index)||numeric;
        }
        if (s[index]=='e'||s[index]=='E')
        {
            ++index;
            numeric = numeric && scanInt(s, &index);
        }
        while (s[index]==' ')
        {
            ++(index);
        }
        return numeric && s[index]=='\0';
    }
};
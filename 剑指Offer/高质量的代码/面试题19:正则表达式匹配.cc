#include <string>
using namespace std;

//考虑使用递归，来进行解决正则表达式匹配问题；
class Solution {
public:
    bool matchcore(string s, string p){
        if (p.empty()) return s.empty();
        if (p[1]=='*'){
            return matchcore(s, p.substr(2)) || (!s.empty()&&(s[0]==p[0]||p[0]=='.'))&& matchcore(s.substr(1),p);
        }
        else{
            return !s.empty() && (s[0]==p[0]||p[0]=='.')&&matchcore(s.substr(1), p.substr(1));
        }
    }
    // 判断两个字符是否匹配；
    bool isMatch(string s, string p) {
        return matchcore(s, p);
    }
};
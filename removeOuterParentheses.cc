/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2019-08-27 10:51:32
 * LastEditTime: 2019-08-27 11:03:56
 * Description: 删除最外层括号
 */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        int count=0;
        string str = "";
        for(auto s : S){
            if(s == '('){
                count++;
                if(count>1){
                    str += s;
                }
            }else{
                count--;
                if(count>0){
                    str += s;
                }
            }
        }
        return str;
    }
};

int main(int argc, char* argv[]){
    //string S = "(()())(())(()(()))";
    string S = "(()())(())";
    Solution solve;
    cout << solve.removeOuterParentheses(S) << endl;
    return 0;
}
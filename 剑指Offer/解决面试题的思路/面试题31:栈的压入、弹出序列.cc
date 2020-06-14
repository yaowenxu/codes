#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> base;
        int index = 0;
        for (int i = 0; i < popped.size();)
        {
            int topop = popped[i]; // 将要弹出的值；
            bool match = false;
            while (index < pushed.size())
            {
                if (pushed[index] ==  topop)
                {
                    index++;
                    match = true;
                    break;
                }else if(!base.empty()&& base.top() == topop){ // 返回栈顶；
                    base.pop();
                    match = true;
                    break;
                }else{
                    base.push(pushed[index]); // 推入到base栈中；
                    index++;
                }
            }

            if(index==pushed.size()&&!base.empty()&& base.top() == topop){// 处理所以数组都在栈中的情况
                base.pop(); 
                match = true;
            }

            if (match == true)
            {
                i++;
            }else{
                if (index == pushed.size())
                {
                    return false; // 返回错误结果；
                }
            }
        }
        return true;
    }
}; 
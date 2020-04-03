/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-03 23:13:43
 * LastEditTime: 2020-04-03 23:27:08
 * Description: 用两个栈来实现队列；
 */

#include <stack>
using namespace std;
class CQueue {
public:
    stack<int> s1; // 创建第一个栈；
    stack<int> s2; // 创建第二个栈；
    CQueue(){} // 直接声明类；
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        int res = -1;
        if (!s2.empty())
        {
            res = s2.top(); 
            s2.pop(); // s2 弹出栈中的值; 
        }else{
            while (!s1.empty())
            {
                int v = s1.top();
                s1.pop();
                s2.push(v);
            }
            if (!s2.empty()) 
            {
                res = s2.top(); 
                s2.pop(); // s2 弹出栈中的值; 
            }
        }
        return res;
    }
};
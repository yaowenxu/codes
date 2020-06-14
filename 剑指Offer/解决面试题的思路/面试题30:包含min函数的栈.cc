#include <stack>
using namespace std;
// 利用两个栈来进行模拟；
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> base;
    stack<int> minstk;
    
    MinStack() {}
    
    void push(int x) {
        if (base.size()==0)
        {
            minstk.push(x);
        }else
        {
            if (x <= minstk.top())
            {
                minstk.push(x);
            }else{
                minstk.push(minstk.top());
            }
        }
        base.push(x);
    }
    
    void pop() {
        base.pop();
        minstk.pop();
    }
    
    int top() {
        return base.top();
    }
    
    int min() {
        return minstk.top();
    }
};
//  C++ STL 栈操作 stack；

#include <iostream>
#include <stack>
#include <vector>
#include <deque>

using namespace std;

struct Node
{
    int a;
    int b;
    Node (int x, int y){
        a = x;
        b = y;
    }
};

int main(){
    // 栈的初始化；
    stack<int> first; // 声明栈；
    deque<int> first_deque(3, 10);
    
    stack<int, vector<int> > second; // 声明栈，底层使用vector构建；
    vector<int> first_vector(2, 11);

    cout << first.size() << endl; // 返回栈的长度；
    cout << first_deque.size() << endl;
    cout << second.size() << endl;
    cout << first_vector.size() << endl;

    // 常用操作；
    // size empty pop push top swap
    first.push(10086); // 将参数加入栈中，没有返回值；
    cout << first.size() << endl; // 返回栈的长度；
    cout << first.empty() << endl; // 判断栈是否为空；栈为空时返回true;
    cout << first.top() << endl; // 返回栈顶元素，但不删除栈顶元素；
    cout << first.size() << endl; 
    first.pop(); // 删除栈顶元素，但是没有返回值；
    cout << first.size() << endl; 

    // 使用结构体初始化栈
    stack<Node> third;
    third.emplace(1, 2);
    // emplace 可以将一个元素加入栈中，与push的区别在于，emplace可以直接传入Node的构造函数的参数，并将构造的元素加入栈中。
    third.push(Node(3, 4)); // 将node加入栈中。

    cout << third.size() << endl;

    // swap 内存交换操作；
    stack<Node> fourth;
    fourth.swap(third);
    cout << third.size() << " " << fourth.size() << endl;

    return 0; // 进行给系统返回程序的返回值。
}
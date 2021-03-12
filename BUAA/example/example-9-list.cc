// c++ stl list 练习
// 参考：https://www.cnblogs.com/linuxAndMcu/p/10260627.html
// 编译命令：c++ -std=c++11 example-9-list.cc -o out ; ./out ; rm out

#include <iostream>
#include <list>
#include <deque>
using namespace std;

// list 由双向链表实现，支持比较高效的插入和删除操作；

list<int> a1; // 定义一个int类型的列表a
list<int> a2(10); // 定义一个int类型的列表a，并设置初始大小为10
list<int> a3(10, 1); // 定义一个int类型的列表a，并设置初始大小为10且初始值都为1
list<int> b1(a1); // 定义并用列表a初始化列表b
list<int> b2(a2.begin(), ++a2.end()); // 将列表a中的第1个元素作为列表b的初始值

int main(){

    cout << "list" << endl;
    cout << a3.size() << endl;
    cout << a3.empty() << endl;
    a3.resize(5);
    cout << a3.size() << endl;
    cout << a3.max_size() << endl; // 输出list最大长度；
    deque<int> deq;
    cout << deq.max_size() << endl; // 输出deque的最大长度；

    list<int> li;
    li.push_front(1); // 添加操作；无返回值；
    li.push_back(2);
    li.insert(li.end(), 3); // 插入操作；
    li.emplace_front(0);
    li.emplace_back(4); // 进行将数据添加到结尾；
    li.pop_front();
    li.pop_back();
    li.erase(--li.end()); // 注意迭代器重载了--运算符；

    cout << li.size() << endl;

    li.push_back(2);
    li.unique(); // 去除list中相同元素；

    list<int> li2;
    li2.push_back(5); 
    li2.push_back(4);
    li.splice(++li.begin(), li2); // 进行拼接；
    li.merge(li2);

    // list 结构体自身的算法；
    li.sort(); // 进行对list排序；
    li.reverse(); // 进行对list反转；

    // 进行遍历输出list，注意list不支持基于下标的随机读取；
    for (auto it = li.begin(); it != li.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
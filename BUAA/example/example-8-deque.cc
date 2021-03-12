// c++ stl deque 练习
// 参考：https://www.cnblogs.com/linuxAndMcu/p/10260124.html
// 编译命令：c++ -std=c++11 example-8-deque.cc -o out ; ./out ; rm out

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

deque<int> a1;                             // 定义一个int类型的双端队列a
deque<int> a2(10);                         // 定义一个int类型的双端队列a，并设置初始大小为10
deque<int> a3(10, 1);                      // 定义一个int类型的双端队列a，并设置初始大小为10且初始值都为1
deque<int> b1(a1);                         // 定义并用双端队列a初始化双端队列b
deque<int> b2(a2.begin(), a2.begin() + 3); // 将双端队列a中从第0个到第2个(共3个)作为双端队列b的初始值

int main()
{
    vector<int> vec;
    cout << vec.max_size() << endl;
    deque<int> deq;
    cout << deq.max_size() << endl;
    deq.push_back(2); // 添加队列到双端队列后；
    cout << deq.front() << endl;
    deq.push_front(1); // 添加元素到双端队列前；
    cout << deq.front() << endl;
    deq.resize(1);               // 重新设置队列的大小；
    cout << deq.size() << endl;  // 获取deque的大小；
    cout << deq.empty() << endl; // 进行判空双端队列；

    deq.insert(deq.begin(), 3); // 进行插入元素
    cout << deq.size() << endl;

    deq.pop_front();            // 删除双端队列前的元素
    deq.pop_back();             // 删除双端队列后的元素
    deq.assign(3, 1);           // 进行赋值队列内容为三个1;
    deq.assign(3, 2);           // 进行赋值后，队列的内容会发生改变。
    cout << deq.size() << endl; // 获取双端队列长度；

    // deq.begin deq.end 正向迭代指针；
    // deq.cbegin deq.cend 正向常量迭代指针；
    // deq.rbegin deq.rend 反向迭代指针。

    // 遍历；
    deque<int>::iterator it;
    for (it = deq.begin(); it != deq.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    deq.emplace_front(3);
    deq.emplace_back(1);

    sort(deq.begin(), deq.end());
    reverse(deq.begin(), deq.end()); // 进行反向排列；

    // 使用index遍历；
    for (int i = 0; i < deq.size(); i++)
    {
        cout << deq.at(i) << " ";
    }
    cout << endl;
    
    deq.clear(); // 进行清空双端队列；
    cout << deq.size() << endl;

    // 相比较于vector, deque数据结构没有capacity函数和data函数，其内存上也不是连续的。

    return 0;
}
// c++ stl set 练习
// 参考：https://www.cnblogs.com/linuxAndMcu/p/10261014.html
// 编译命令：c++ -std=c++11 example-10-set.cc -o out ; ./out ; rm out

#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

set<int> a; // 定义一个int类型的集合a
// set<int> a(10); // error，未定义这种构造函数
// set<int> a(10, 1); // error，未定义这种构造函数
set<int> b(a); // 定义并用集合a初始化集合b
set<int> b2(a.begin(), a.end()); // 将集合a中的所有元素作为集合b的初始值


int main(){
    int n[] = { 1, 2, 3, 4, 1};
    set<int> st(n, n + 5); // 将数组n的前5个元素作为集合a的初值

    // 容量函数；
    cout << st.size() << endl; // 表示输出的长度；
    vector<int> vec;
    list<int> li;
    cout << st.max_size() << endl;
    cout << vec.max_size() << endl;
    cout << li.max_size() << endl;
    cout << st.empty() << endl;

    st.insert(5); // 插入元素5；
    st.insert(st.begin(), 6); // 进行插入元素6；

    // 删除set中元素；
    st.erase(st.begin());
    st.erase(4); // 进行删除为4的元素；

    // 进行遍历set，输出set中的值；
    for (auto it = st.begin(); it != st.end(); it++)
    {
        cout << *it << " "; // 输出st中的值；
    }
    cout << endl; // 从输出可见set是排好序的；

    // 找到元素为 5 的位置；
    set<int>::iterator it;
    it = st.find(5); // 如果不成功返回 st.end();
    cout << *(++it) << endl; //输出it所指的数值。 // 注意对容器的迭代器的使用；
    it = st.lower_bound(1); // num >= key
    cout << *(it) << endl;

    it = st.upper_bound(2); // num > key
    cout << *(it) << endl;

    pair<set<int>::iterator, set<int>::iterator> t_pair = st.equal_range(5);
    cout << *t_pair.first << endl;
    cout << *t_pair.second << endl;
    
    // 清空 set
    st.clear(); 
    cout << st.size() << endl;

    // set 不支持 resize操作，不支持下标操作；只提供
    // set 只能使用insert进行插入，不支持push_back和push_front操作；
    // set 本身为已经排序，所以 set 不支持 STL 里的 reverse 和 sort 算法。

    return 0; 
}
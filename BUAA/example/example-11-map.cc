// c++ stl map 练习
// 参考：https://www.cnblogs.com/linuxAndMcu/p/10261263.html
// 编译命令：c++ -std=c++11 example-11-map.cc -o out ; ./out ; rm out

#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

map<int, string> a; // 定义一个int类型的映射a
// map<int, string> a(10); // error，未定义这种构造函数
// map<int, string> a(10, 1); // error，未定义这种构造函数
map<int, string> b(a); // 定义并用映射a初始化映射b
// map<int, string> b(a.begin(), a.end());  // error，未定义这种构造函数

int main(){
    set<int> st; // 声明st
    map<int, int> mp; // 声明map
    vector<int> vec; // 声明vec
    cout << "map" << endl;
    cout << st.max_size() << endl;
    cout << mp.max_size() << endl;
    cout << vec.max_size() << endl;
    mp[1] = 1;
    cout << mp.size() << endl;
    cout << mp.empty() << endl; // 判断map是否为空
    cout << mp.count(1) << endl; // 返回键的个数，针对于multimap;

    //添加函数
    mp.insert({2, 2});
    mp.insert(mp.begin(), pair<int, int>{3, 3}); // 插入pair对；
    mp.erase(2);
    cout << mp.size() << endl; // 返回mp的个数；
    mp.insert(mp.begin(), {6, 6}); // 进行将大数插入在前，判断map是否自动排序；

    // 遍历访问；
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << endl;
    }
    auto iit = mp.find(3);
    cout << (iit==mp.end()) << endl;

    // 迭代器访问；
    // 针对于 multimap 其有 lower_bound upper_bound 和 equal_range；三种不同的访问方式。
    // map可以使用下标进行访问；
    
    return 0;
}
// c++ stl 算法部分 练习
// 参考：https://www.cnblogs.com/linuxAndMcu/p/10264339.html
// 编译命令：c++ -std=c++11 example-12-algo.cc -o out ; ./out ; rm out

// STL 算法部分主要由头文件 algorithm numeric functional 三个部分组成。

// STL 中算法分类：
// 非可变序列算法：不直接修改其所操作的容器内容的算法；
// 可变序列算法：指可以修改所操作的容器内容的算法；
// 排序算法：对序列进行排序的算法，合并的算法，搜索算法，以及在有序序列上集合操作。
// 数值算法：对容器内容进行数值计算。

// 本代码，只展示常用部分；其他相关函数待补充。

#include <iostream>
#include <algorithm>  // 算法函数
#include <numeric>    // 数值算法
#include <functional> // 模板类算法
#include <vector>
#include <iterator> // 迭代器
#include <set>
#include <time.h>
using namespace std;
void display_vec(vector<int> &vec)
{
    for (auto i = vec.cbegin(); i != vec.cend(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}

void display_set(set<int> &st)
{
    for (auto i = st.cbegin(); i != st.cend(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}

int main()
{
    srand(static_cast<unsigned int>(time(0))); //随机种子；如果不加种子，每次随机结果都一样。
    cout << "algo" << endl;
    vector<int> vec1 = {0, 1, 2, 3, 4, 5, 6, 9, 6, 7, 8};
    vector<int> vec2 = {12, 10};
    vector<int> vec3;
    vec3.resize(vec1.size() + vec2.size());
    display_vec(vec1);
    display_vec(vec2);
    merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin()); // 进行合并；
    display_vec(vec3);

    // 排序和随机算法；
    sort(vec3.begin(), vec3.end());
    display_vec(vec3);
    random_shuffle(vec3.begin(), vec3.end()); // 进行打乱vec数组-1；
    display_vec(vec3);
    random_shuffle(vec3.begin(), vec3.end()); // 进行打乱vec数组-2；
    display_vec(vec3);
    random_shuffle(vec3.begin(), vec3.end()); // 进行打乱vec数组-3；
    display_vec(vec3);
    stable_sort(vec3.begin(), vec3.end()); // 进行稳定排序；
    reverse(vec3.begin(), vec3.end());
    display_vec(vec3); // 展示数组内容；

    // set 算法
    set<int> st1 = {1, 3, 5, 7, 9, 11};
    set<int> st2 = {1, 2, 3, 5, 8};
    set<int> res;
    display_set(st1);
    display_set(st2);

    // 并集
    set_union(st1.begin(), st1.end(), st2.begin(), st2.end(), inserter(res, res.begin()));
    display_set(res);

    // 交集
    set_intersection(st1.begin(), st1.end(), st2.begin(), st2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // 差集 set1 - set2
    set_difference(st1.begin(), st1.end(), st2.begin(), st2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // 对称差集 并集-交集, 并按照排好的顺序输出。
    set_symmetric_difference(st1.begin(), st1.end(), st2.begin(), st2.end(), ostream_iterator<int>(cout, " "));
    cout << endl; 

    // 堆操作 未展示；
    return 0; // 进行返回函数；
}

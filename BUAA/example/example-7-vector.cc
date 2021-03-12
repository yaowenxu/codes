// c++ vector的练习；
// 编译命令：c++ -std=c++11 example-7-vector.cc -o out ; ./out ; rm out
// 参考：https://www.cnblogs.com/linuxAndMcu/p/10259630.html

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a1; // 定义一个int类型的向量a
vector<int> a2(10); // 定义一个int类型的向量a，并设置初始大小为10
vector<int> a3(10, 1); // 定义一个int类型的向量a，并设置初始大小为10且初始值都为1
vector<int> b1(a2); // 定义并用向量a初始化向量b
vector<int> b2(a3.begin(), a3.begin()+3); // 将a向量中从第0个到第2个(共3个)作为向量b的初始值
bool comp(const int& a, const int& b); // 排序函数，用于vec算法操作；

int main(){
    int n[] = {1, 2, 3, 4, 5};
    vector<int> a4(n, n+5); // 末尾指针，表示指向最后一个元素的下一个位置；这是为了和vec.end相对应；
    cout << a4.size() << endl; // 进行输出数组的大小。
    vector<int> a5(&n[1], &n[4]); // 将n[1]、n[2]、n[3]作为向量a的初值
    
    // 容器函数
    cout << a3.size() << endl; // 容器大小；
    cout << a3.capacity() << endl; // 容器容量；
    cout << a3.max_size() << endl; // 容器最大容量 4611686018427387903
    a3.resize(2);   // 更改容器大小；
    cout << a3.size() << endl; 
    cout << a3.capacity() << endl;
    cout << a3.empty() << endl; // 判断容器是否为空；

    // 添加函数
    vector<int> vec;
    vec.push_back(5); // 添加5；
    vector<int>::iterator it;
    it = vec.begin();
    vec.insert(it, 2); // 插入2；
    cout << vec.size() << endl;
    it = vec.begin(); // it 每次使用后，都要更新；
    vec.insert(it, 3, 0);
    cout << vec.size() << endl;
    
    vector<int> vec2(5, 8);
    it = vec.begin();
    vec.insert(it, vec2.end()-1, vec2.end());
    cout << vec.size() << endl;

    // 访问元素
    cout << vec.front() << endl;
    cout << vec.back() << endl;
    cout << vec.size() << endl;
    cout << *vec.data() << endl;

    // 删除元素；
    vec.pop_back();
    cout << vec.size() << endl;
    it = vec.begin();
    vec.erase(it);
    cout << vec.size() << endl;
    vec.erase(vec.begin(), vec.end()-1);
    cout << vec.size() << endl;
    vec.clear();
    cout << vec.size() << endl;

    vec.push_back(1);
    cout << vec.size() << endl;
    vec.swap(a3);
    cout << vec.size() << endl;
    cout << a3.size() << endl;

    struct Node
    {
        int a;
        int b;
        Node(int x, int y){
            a = x;
            b = y;
        }
    };

    //emplace emplace_back 的用法；
    vector<Node> node_vec;
    node_vec.emplace_back(1, 2);

    // 算法
    // 元素反转
    reverse(node_vec.begin(), node_vec.end());

    // 元素排序，升序排列
    sort(a3.begin(), a3.end());

    // 元素排序，降序排列
    sort(a3.begin(), a3.end(), comp); // 进行比较元素并排序；
    cout << a3.size() << endl;

    return 0;
}

bool comp(const int& a, const int& b){
    return a > b;
}
// 编译命令：c++ Q3.cc -std=c++11 -o out; ./out ; rm out
// 找家谱成员；
// 题目分析，建议在纸上画出家族树的关系；初步一看是树的遍历问题；仔细分析后是对关系的记录；
// 编写程序时，要记录程序是用来解决问题的，不是模拟人来解决问题；一定要处理好解题思路，熟练使用数据结构；
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <deque>
using namespace std;

int main(){
    freopen("Q3.in", "r", stdin); // 重定向标准输入到文件；
    vector<string> buf;
    map<string, string> pointfa; // 指向自己的父亲;
    bool root = true;
    while(!cin.eof()){
        string str;
        cin >> str;
        buf.push_back(str);
        if (buf.size() == 3)
        {
            string fa = buf[0]; 
            string firstchild = buf[1]; // 第一个孩子；
            string secondchild = buf[2]; // 第二个孩子；
            buf.clear(); // 进行清空缓冲区；
            if(root){
                pointfa[fa] = "";
                root = false;
            }
            pointfa[firstchild] = fa;
            pointfa[secondchild] = fa;
        }
    }
    string first = buf[0]; // 第一个成员；
    string second = buf[1]; // 第二个成员；
    deque<string> fasdq1; // 祖先的队列；
    deque<string> fasdq2; // 祖先的队列；

    // 寻找成员1的祖先队列；
    string find = first; 
    while(pointfa[find] != ""){
        fasdq1.push_front(pointfa[find]);
        find =  pointfa[find]; // 进行更新祖先；
    }

    // 寻找成员2的祖先队列；
    find = second; 
    while(pointfa[find] != ""){
        fasdq2.push_front(pointfa[find]);
        find =  pointfa[find]; // 进行更新祖先；
    }
    auto it1 = fasdq1.begin(); 
    auto it2 = fasdq2.begin();

    string same = ""; // 标记共同祖先；

    while (*it1 == *it2)
    {
        same = *it1; // 进行记录最近的祖先；
        it1++;
        it2++;
    }

    int l = 0; // 表示层次数；

    if (fasdq1.size() > fasdq2.size())
    {
        l = fasdq1.size() - fasdq2.size();
    }else{
        l = fasdq2.size() - fasdq1.size(); // 表示层次数；
    }
    
    cout << same << " " << l << endl;

    return 0;
}
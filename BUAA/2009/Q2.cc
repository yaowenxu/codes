// 数组排序
// 编译命令：c++ -std=c++11 Q2.cc -o out ; ./out ; rm out

#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
    freopen("Q2.in", "r", stdin);
    int n = 0;
    while (scanf("%d", &n)!=EOF)
    {
        vector<int> vec;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int num = 0;
            scanf("%d", &num);
            vec.push_back(num); // 进行将数字保存起来；
            mp[num] = num; // 进行设置map;
        }
        int cnt = 0;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            cnt += 1;
            mp[it->first] = cnt;
        }
        // 进行循环输出；
        bool first = true;
        for (auto it = vec.begin(); it != vec.end(); it++)
        {
            if (first)
            {
                first = false;
            }else{
                cout << " ";
            }
            cout << mp[*it]; // 进行输出序列；
        }
    }
    return 0;
}
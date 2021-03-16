// 判断数组是否相等；

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 通过对数组排序，或者稳定排序；进行对比是否相同；

int main()
{
    freopen("Q3.in", "r", stdin);
    int size = 0;
    while (scanf("%d", &size) != EOF)
    {
        vector<int> vec1; // 第一个数组
        vector<int> vec2; // 第二个数组
        for (int i = 0; i < size; i++)
        {
            int n = 0;
            scanf("%d", &n);
            vec1.push_back(n);
        }
        for (int j = 0; j < size; j++)
        {
            int n = 0;
            scanf("%d", &n);
            vec2.push_back(n);
        }
        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());
        for (int i = 0; i < size; i++)
        {
            if (vec1[i]!=vec2[i])
            {
                cout << "not equal!" << endl;
                return 0;
            }
        }
        cout << "equal!" << endl; // 判断相等；
    }
    return 0;
}
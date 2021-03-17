#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

bool set_same(int a[], int len1, int b[], int len2){
    set<int> seta;
    set<int> setb;
    set<int> setc;
    for (int i = 0; i < len1; i++)
    {
        seta.insert(a[i]);
    }
    for (int i = 0; i < len2; i++)
    {
        setb.insert(b[i]);
    }
    set_symmetric_difference(seta.begin(), seta.end(), setb.begin(), setb.end(), inserter(setc, setc.begin()));
    return setc.empty();
}

int main(){
    freopen("Q1.in", "r", stdin); // 重定向标准输入输出；
    int a;
    int b;
    while (scanf("%d", &a)!=EOF)
    {
        vector<int> veca;
        vector<int> vecb;
        for (int i = 0; i < a; i++)
        {
            int tmp = 0;
            scanf("%d", &tmp);
            veca.push_back(tmp); // 放置到向量后；
        }
        scanf("%d", &b);
        for (int i = 0; i < b; i++)
        {
            int tmp = 0;
            scanf("%d", &tmp);
            vecb.push_back(tmp); //放置到向量后；
        }
        if (set_same(veca.data(), veca.size(), vecb.data(), vecb.size()))
        {
            cout << "equal!" << endl;
        }else{
            cout << "not equal!" << endl;
        }
    }
    
    return 0;
}
// 中位数的位置；
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct NUM{
    int value;
    int order;
};

// 已定义比较函数；
bool CMP(const NUM &a, const NUM &b){
    return a.value <= b.value;
}

// 进行对输入的数据进行排序，注意此处需要使用稳定排序；对于相等的数字，需要保证其输入的顺序；
int main(){
    freopen("Q1.in", "r", stdin); // 重定向输入到文件；
    int n = 0;
    while (scanf("%d", &n)!=EOF)
    {
        vector<NUM> vec;
        for (int i = 0; i < n; i++)
        {
            NUM num;
            scanf("%d", &num.value); // 进行输入数据;
            num.order = i + 1;
            vec.push_back(num); 
        }
        stable_sort(vec.begin(), vec.end(), CMP); // 进行对vec进行排序；
        // cout << vec.size() << endl;
        if (vec.size() % 2 == 0)
        {
            cout << vec[vec.size()/2-1].value << " " << vec[vec.size()/2-1].order << endl;
            cout << vec[vec.size()/2].value << " " << vec[vec.size()/2].order << endl;
        }else{
            cout << vec[vec.size()/2].value << " " << vec[vec.size()/2].order << endl;
        }
    }
    return 0;
}
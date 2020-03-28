/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-03-28 12:32:38
 * LastEditTime: 2020-03-28 12:49:35
 * Description: 顺序查找
 * 测试数据：1 2 3 500 9 7 6
 */

#define DEBUG 1
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
void printarray(vector<int> &arr);

void seqsearch(vector<int> &arr, int v=500){
    cout << "开始查找数据：" << v << endl;
    bool flag =  true;
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == v){
            cout << "满足索引：" << i << endl;
            flag = false;
        }
    }
    if (flag)
    {
        cout << "无满足数据！" << endl;
    }
}

// 打印函数；
void printarray(vector<int> &arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr; 
    freopen("in.txt", "r", stdin); // 重定向到输入 
    int i = 0; 
    int tmp; 
    while (cin >> tmp)
    {   
        arr.push_back(tmp);
        // cout << inarray[i] << endl;
        i++;
    }
    int num =  i;
    cout << "输入数据：" << endl;
    printarray(arr);
    cout << endl;
    if (DEBUG){
        cout << "查找过程：" << endl;
    }

    // 顺序查找
    seqsearch(arr);
    return 0;
}
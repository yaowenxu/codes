/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-03-27 15:11:24
 * LastEditTime: 2020-03-27 15:37:57
 * Description: 基数排序，桶排序算法；利用数据规律来进行排序;
 * 测试数据：614 738 921 485 637 101 215 530 790 306
 */

#define DEBUG 1
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
void printarray(vector<int> &arr);

// 针对于整数的桶排序
void bucketsort(vector<int> &arr, int base){
    int n = arr.size(); // 确定待排序数字的总数；
    //建立10个桶
    vector<int> bucket[10];
    for(int i = 0; i < n; i++){
        bucket[(arr[i]/base)%10].push_back(arr[i]);
    }
    if(bucket[0].size()==n){
        return; //递归出口
    }
    int index = 0;
    for(int i = 0; i < 10; i++){
        for (int j = 0; j < bucket[i].size(); j++)
        {
            arr[index] = bucket[i][j];
            index++;
        }
    }
    if(DEBUG){
        printarray(arr);
    }
    bucketsort(arr, base*10);
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
        cout << "排序过程：" << endl;
    }

    // 基数排序
    bucketsort(arr, 1); // 桶排序算法；

    if (DEBUG){
        cout << endl;
    }
    cout << "排序结果：" << endl;
    printarray(arr);
    return 0;
}
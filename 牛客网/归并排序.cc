/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-03-27 12:16:16
 * LastEditTime: 2020-03-27 13:18:04
 * Description: 归并排序，先把数组进行分解；然后逐次对每个有序数组进行合并；
 * 测试集: 1 5 10 3 4 
 * Tips: 只有合并后
 */

#define DEBUG 1
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
void printarray(vector<int> &arr);

void printij(vector<int> &arr, int i, int j){
    for (;i <= j; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(vector<int> &arr, int start, int mid, int end){
    if(DEBUG){
        cout << "合并前：" << endl;
        printij(arr, start, mid);
        printij(arr, mid+1, end);
    }
    // 归并阶段
    vector<int> tmp; // 创建一个数据，用于保存归并排序的中间变量；
    int i = start;
    int s = start;
    int j = mid+1;
    while (i<= mid && j <=end)
    {
        if(arr[i]>=arr[j]){
            tmp.push_back(arr[j]);
            j++;
        }else{
            tmp.push_back(arr[i]);
            i++;
        }
    }
    if (i>mid){
        while (j<=end)
        {
            tmp.push_back(arr[j]);
            j++;
        }
    }
    if (j > end){
        while (i<=mid)
        {
            tmp.push_back(arr[i]);
            i++;
        }
    }
    for (int k = 0; k < tmp.size(); k++)
    {
        arr[start] = tmp[k]; // 注意此处的数组起点为 start;
        start++;
    }
    if (DEBUG)
    {
        cout << "合并后：" << endl;
        printij(arr, s, end);
        cout << endl;
    }
}

void mergesort(vector<int> &arr, int start, int end){
    if (DEBUG)
    {
        cout << "分解阶段: " << start << " " << end << endl;
    }
    if (start == end) return; // 递归出口
    int mid =  (end+start)/2;
    mergesort(arr, start, mid);
    mergesort(arr, mid+1, end);
    // 不同于快速排序，归并排序更强调于merge
    // merge 
    if (DEBUG)
    {
        cout << "合并阶段: " << start << " " << mid << " " << end << endl;
    }
    merge(arr, start, mid, end);
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

    // 归并排序
    mergesort(arr, 0, arr.size()-1);

    if (DEBUG){
        cout << endl;
    }
    cout << "排序结果：" << endl;
    printarray(arr);
    return 0;
}
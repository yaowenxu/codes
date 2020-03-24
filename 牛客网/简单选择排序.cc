/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-03-24 11:25:17
 * LastEditTime: 2020-03-24 11:42:27
 * Description: 简单选择排序，进行搜索并排序；并与排序好的末尾元素替换；
 */

#define DEBUG 1
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
void printarray(vector<int> &arr);

//直接插入排序
void selectsort(vector<int> &arr){
    int size = arr.size();
    for (int i = 0; i < size-1; i++){ // 此处size-1是为了j = i+1到达末尾时，不会越界；
        int min = arr[i];
        int index = i;
        for (int j = i+1; j < size; j++){
            if(arr[j] < min){
                min = arr[j];
                index =  j;
            }
        }
        arr[index] = arr[i];
        arr[i] = min;
        printarray(arr);
    }
}

// 打印函数；
void printarray(vector<int> &arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    if(DEBUG){
        //cout << "left:" << left << " " << "right:" << right << endl;
    }
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

    // 插入排序算法调用；其他代码为调试输出代码；
    selectsort(arr);

    if (DEBUG){
        cout << endl;
    }
    cout << "排序结果：" << endl;
    printarray(arr);
    return 0;
}
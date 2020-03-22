/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-03-22 13:13:41
 * LastEditTime: 2020-03-22 15:55:42
 * Description: 快速排序实现: 使用分治方法; 
 * 执行方式: c++ 快速排序.cc; ./a.out
 * 测试数据: 7 8 9 6 5 4 3 2 1
 */
#define DEBUG 1
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
void printarray(vector<int> &arr, int left, int right);

// 分解 第一版本；
int divide_1(vector<int> &arr, int left, int right){
    int base =  arr[left]; // 选取第一个元素为left;
    if(DEBUG){
        cout << endl << "base:" << base << " " << "left:" << left << " " << "right:" << right << endl;
    }
    while (true)
    {
        while (arr[right] >= base && right > left)
        {
            right --;
        }
        if (right == left){
            printarray(arr, left, right);
            break;
        }
        arr[left] = arr[right];
        arr[right] = base;
        left ++;
        printarray(arr, left, right);
        while (arr[left] <= base && left < right)
        {
            left ++;
        }
        if (left == right){
            printarray(arr, left, right);
            break;
        }
        arr[right] = arr[left];
        arr[left] = base;
        right --;
        printarray(arr, left, right);
    }
    return left; // 返回当前 base 所在的索引
}

// 分解第二版本
int divide_2(vector<int> &arr, int left, int right){
    int base = arr[left];
    while (left < right)
    {
        while (left < right && base <= arr[right])
        {
            right --;
        }
        arr[left] = arr[right];
        while (left < right && arr[left] <= base)
        {
            left ++;
        }
        arr[right] =  arr[left];
    }
    arr[left] = base;
    return left; // 返回当前base的索引；
}

// 快速排序算法
void quicksort(vector<int> &arr, int left, int right){
    // 设置递归出口
    if (left >= right){
        return;
    }
    int baseindex = divide_1(arr, left, right);
    quicksort(arr, left, baseindex-1);
    quicksort(arr, baseindex+1, right);
    // 快速排序算法，强调对问题原有数据的分解；
    // 每分解一次，一个元素归位；为减治；
    // 每分解一次，转化为两个独立的子问题；为分治；
}

// 打印函数；
void printarray(vector<int> &arr, int left, int right){
    if((left == -1 && right== -1)|| DEBUG){
        for(int i = 0; i < arr.size(); i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    if((left != -1&&right != -1)&& DEBUG){
        cout << "left:" << left << " " << "right:" << right << endl;
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
    printarray(arr, -1, -1);
    cout << endl;
    if (DEBUG){
        cout << "排序过程：" << endl;
    }

    // 快速排序算法调用；其他代码为调试输出代码；
    quicksort(arr, 0, num-1); 

    if (DEBUG){
        cout << endl;
    }
    cout << "排序结果：" << endl;
    printarray(arr, -1, -1);
    return 0;
}
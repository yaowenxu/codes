/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-03-23 13:38:01
 * LastEditTime: 2020-03-23 14:41:17
 * Description: 希尔排序，直接插入排序的改进版本；
 * 测试数据：7 6 5 3 4 2 1
 */

#define DEBUG 1
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
void printarray(vector<int> &arr);

//希尔插入排序_移动插入方式实现；
void shellsort(vector<int> &arr){
    int size =  arr.size();
    for (int gap = size/2; gap >0; gap /=2)
    {
        cout << "gap: " << gap << endl;
        for (int i = 0; i < gap; i++) // 希尔排序的每次gap;
        {
            for (int j = i+gap; j < size; j += gap) // 类比于插入排序；使用j 抽象出一组序列；
            {
                int toins =  arr[j]; int k;
                cout << toins << endl;
                for (k = j-gap; k >= i; k -= gap)
                {
                    if (arr[k] >= toins)
                    {
                        arr[k+gap] = arr[k];
                    }else
                    {
                        break;
                    }
                }
                arr[k+gap] =  toins; // 使用移动插入的方式进行实现；
                printarray(arr);
            }
        }
    }
}

//希尔排序，使用交换方式实现； 类似于冒泡排序
void shellsort_2(vector<int> &arr){
    int size =  arr.size();
    for (int gap = size/2; gap >0; gap /=2)
    {
        cout << "gap: " << gap << endl;
        for (int i = 0; i < gap; i++) // 希尔排序的每次gap;
        {
            for (int j = i+gap; j < size; j += gap) // 类比于插入排序；使用j 抽象出一组序列；
            {
                int k;
                cout << "toins: " << arr[j] << endl;
                for (k = j-gap; k >= i; k -= gap)
                {
                    if (arr[k] >= arr[k+gap])
                    {
                        int tmp = arr[k+gap];
                        arr[k+gap] = arr[k];
                        arr[k] = tmp;
                    } else {
                        break;
                    }
                }
                printarray(arr);
            }
        }
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
        i++;
    }
    int num =  i;
    cout << "输入数据：" << endl;
    printarray(arr);
    cout << endl;
    if (DEBUG){
        cout << "排序过程：" << endl;
    }

    // 希尔排序算法调用；其他代码为调试输出代码；
    shellsort(arr);

    if (DEBUG){
        cout << endl;
    }
    cout << "排序结果：" << endl;
    printarray(arr);
    return 0;
}
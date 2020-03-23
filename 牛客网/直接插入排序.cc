/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-03-23 11:50:40
 * LastEditTime: 2020-03-23 12:56:19
 * Description: 直接插入排序，从左到右扫描一次数组；将每个元素，插入到左侧有序队列中；
 * Tips: 在插入过程中，如果该数组使用双向链表实现；最为插入最为高校；如果使用数组实现，需要从右边到左移动左侧有序数组，感觉和反向冒泡排序有点像
 * 测试样例: 7 6 5 3 4 2 1 
 */

#define DEBUG 1
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
void printarray(vector<int> &arr);

//直接插入排序
void insertsort(vector<int> &arr){
    int toins;
    for(int i =1;  i < arr.size(); i++){
        toins = arr[i];
        cout << "toins: " << toins << endl;
        int j;
        // 进行循环挪动左侧有序数组，找到待插入位置
        for (j = i-1; j >=0; j--)
        {
            if(arr[j]>= toins){
                arr[j+1] = arr[j];
            }else{
                break;
            }
        }
        arr[j+1] = toins; // 进行插入数组
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
    insertsort(arr);

    if (DEBUG){
        cout << endl;
    }
    cout << "排序结果：" << endl;
    printarray(arr);
    return 0;
}
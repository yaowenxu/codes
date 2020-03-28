/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-03-28 13:05:49
 * LastEditTime: 2020-03-28 14:02:03
 * Description: 二分查找算法
 * 测试元素：1 2 300 4 5 7 8 900，首先需要进行排序；
 */

#define DEBUG 1
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
void printarray(vector<int> &arr);

// 递归实现，找出其中一个满足的方案；如果需要找出所有的满足方案，只要先找出其中一个满足方案，然后在其左右顺序搜索就可以了；(因为数组是排序好的)
void binsearch(vector<int> &arr, int start, int end, int v=900){
    if(DEBUG){
        cout << "s=" << start << " " << "e=" << end << endl;
    }
    if(end < start){
        cout << "无满足数据！" << endl;
        return;
    }
    int mid = (start+end)/2;
    if(arr[mid] == v){
        cout << "满足索引：" << mid << endl;
        return;
    }
    if(arr[mid] < v){
        binsearch(arr, mid+1, end);
    }
    if(arr[mid] > v){
        binsearch(arr, start, mid-1);
    }
}

// 非递归实现，非递归实现使用循环实现，注意循环的出口；以及索引的更新；
void binsearch_2(vector<int> &arr, int v=900){
    int start =  0;
    int end = arr.size()-1;
    int flag = true;
    //使用 do-while 来进行循环
    do {
        int mid = (start+end)/2;
        if(DEBUG){
            cout << "s=" << start << " " << "e=" << end << endl;
        }
        if (arr[mid]==v){
            cout << "满足索引：" << mid << endl;
            flag = false;
            break;
        }
        if (arr[mid] > v){
            end = mid-1;
        }
        if (arr[mid] < v){
            start = mid+1;
        }
    } while (end >= start);
    if(flag){
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
    sort(arr.begin(), arr.end());
    cout << "输入数据：" << endl;
    printarray(arr);
    cout << endl;
    if (DEBUG){
        cout << "查找过程：" << endl;
    }

    // 顺序查找
    cout << "binsearch-递归：" << endl;
    binsearch(arr, 0, arr.size()-1);
    cout << "binsearch-非递归：" << endl;
    binsearch_2(arr);
    return 0;
}
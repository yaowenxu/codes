/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-03-25 11:37:16
 * LastEditTime: 2020-03-25 15:00:11
 * Description: 堆排序为选择排序的一种, 使用大顶堆构建顺序排序；最后一个非叶子节点开始堆化，交换输出堆顶；重新堆化；
 * tips: 算法实现技巧，一定要对每一步操作十分熟悉，了解整个过程；这样再进行编写程序；可以选择在纸上进行画出来；
 * 堆排序测试样例：1 5 10 3 4
 */

#define DEBUG 1
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
void printarray(vector<int> &arr);

// 交换数组中 i j 两个数字的位置；
void swapij(vector<int> &arr, int i, int j){
    int tmp =  arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void heapify(vector<int> &arr, int n, int index){
    int max = index;
    int c1 = 2*index+1;
    int c2 = 2*index+2;
    if(c1 < n && arr[c1] > arr[max]){ // c1 >= arr.size()，该节点没有左孩子；
        max = c1;
    }
    if(c2 < n && arr[c2] > arr[max]){ // c2 >= arr.size()，该节点没有右孩子；
        max = c2;
    }
    if(max != index){ // 递归出口，改节点最大值不是index本身；
        swapij(arr, index, max);
        heapify(arr, n, max);
    }
}

void build_heap(vector<int> &arr){
    // 从最后一个非叶子节点开始；
    int n = arr.size();
    for(int i = n/2; i>=0; i--){
        heapify(arr, n, i);
        if (DEBUG){
            printarray(arr);
        }
    }
}

// 使用堆排序进行堆化；
void heapsort(vector<int> &arr){
    if(DEBUG){
        cout << "创建堆：" << endl;
    }
    build_heap(arr); // 第一步创建堆
    // 交换输出堆顶，重新堆化
    if(DEBUG){
        cout << "交换输出堆顶，重新堆化：" << endl;
    }
    int n = arr.size();
    for(int i = n-1; i>0; i--){
        swapij(arr, 0, i); // 交换堆尾和堆顶元素；
        heapify(arr, i, 0); // 重新对堆顶进行堆化；借助于i,每次缩小一个规模；
        if (DEBUG){
            printarray(arr);
        }
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
        cout << "排序过程：" << endl;
    }

    // 堆排序；
    heapsort(arr);

    if (DEBUG){
        cout << endl;
    }
    cout << "排序结果：" << endl;
    printarray(arr);
    return 0;
}
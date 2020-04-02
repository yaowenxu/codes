/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-02 11:33:53
 * LastEditTime: 2020-04-02 11:49:35
 * Description: 指针和数组
 */

#include <iostream>
using namespace std;

int getsize(int* data){
    return sizeof(data); // 返回data数组的大小；
}

int main(){
    cout << "指针和数组：" << endl;
    int data1[] = {1,2,3,4,5};
    int size1 =  sizeof(data1);
    int* data2 = data1; 
    int size2 = sizeof(data2);
    int size3 = getsize(data1);
    // 64位系统中，指针的大小为8个bytes; 
    cout << size1 << " " << size2 << " " << size3;
    return 0;
}
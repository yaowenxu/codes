/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-03-20 19:26:04
 * LastEditTime: 2020-03-22 13:15:40
 * Description: 冒泡排序实现
 */
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> inarray;
int main(){
    freopen("in.txt", "r", stdin); // 重定向到输入 
    int i = 0; 
    int tmp; 
    // 方法1
    while (cin >> tmp)
    {   
        inarray.push_back(tmp);
        // cout << inarray[i] << endl;
        i++;
    }
    int num =  i;
    cout << "输入数据：" << endl;
    for(i = 0; i < num; i++){
        cout << inarray[i] << " ";
    }
    cout << endl << endl;
    cout << "排序过程：" << endl;
    for(i=1; i < num; i++){
        for (int j = 0; j < num-i;j++){
            if(inarray[j] >= inarray[j+1]){
                int tmp = inarray[j];
                inarray[j] = inarray[j+1];
                inarray[j+1] = tmp;
            }
        }
        for(int k = 0; k < num; k++){
            cout << inarray[k] << " ";
        }
        cout << endl;
    }
    for(i = 0; i < num; i++){
        cout << inarray[i] << " ";
    }
    cout << endl;
    return 0;
}
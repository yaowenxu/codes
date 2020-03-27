/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-03-20 15:41:04
 * LastEditTime: 2020-03-20 15:48:10
 * Description: 序列和
 */

#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    freopen("in.txt", "r", stdin); // 输入输出重定向；
    int N; int L;
    cin >> N;
    cin >> L;
    int flag = false;
    for(int i = L; i<=100 ;i++){
        int sum = ((i-1+0)*(i))/2;
        int minus = N - sum;
        if (minus <0){
            break;
        }
        if((minus%i) == 0){
            flag = true;
            int base = minus/i;
            cout << base+0;
            for(int j = 1; j< i; j++){
                cout<< " " << j+base;
            }
            break;
        }
    }
    if(!flag){
        cout << "No";
    }
    return 0;
}
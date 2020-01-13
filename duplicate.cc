/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-01-13 13:29:32
 * LastEditTime: 2020-01-13 14:46:39
 * Description: 文件描述信息
 */
#include <iostream>
using namespace std;

bool duplicate1(int numbers[], int length, int* duplication){
    if(numbers==nullptr || length == 0){
        return false;
    }

    int* hashtable = new int[length];
    for(int i = 0; i < length; i++){
        hashtable[numbers[i]] = hashtable[numbers[i]]+1;
    }
    int count = 0;
    for(int i = 0; i < length; i++){
        if (hashtable[i] > 1)
        {
            duplication[count++] = i;
            return true;
        }
    }
    return false;
}

bool duplicate2(int numbers[], int length, int* duplication) {
    if(numbers==nullptr || length <= 0){
        return false;
    }
    for(int i = 0; i < length; i++){
        if(numbers[i] < 0 || numbers[i] > length-1)
            return false;
    }

    for(int i = 0; i < length; i++){
        while (numbers[i]!=i)
        {
            if(numbers[i]==numbers[numbers[i]]){
                *duplication = numbers[i];
                return true;
            }
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }
    return false;
}


int main(){
    cout << "duplicate" << endl;
    int a = 10;
    int* hash = new int[a];
    for(int i = 0; i < a; i ++){
        //cout << (hash[i]==0?true:false) << endl;
    }
    return 0;
}



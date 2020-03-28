/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-03-28 17:26:30
 * LastEditTime: 2020-03-28 18:20:58
 * Description: 顺序表结构
 */

#include <iostream>
using namespace std;

struct SeqTable{
    int cap; // 容量；
    int size; // 当前元素的个数；
    int *mem;
    int index;
    SeqTable(int n = 10){
        mem =  (int*)malloc(n*sizeof(int)); //声明内存空间
        cap = 10;
        size = 0;
    }
    ~SeqTable(){
        free(mem); // 进行析构内存空间；
    }
    int& operator[] (int i){
        if(i >= cap || i <0 ){
            cerr << "下标越界, 致命错误" << endl; 
        }
        return mem[i];
    }
    void setidx(int i, int v){
        if(i >= size){
            size = i+1;
        }
        if(i >= cap || i <0 ){
            cerr << "下标越界, 致命错误" << endl; 
            return;
        }
        mem[i] = v;
    }
    int getsize(){
        return size;
    }
    int getcapacity(){
        return cap;
    }
    void print(){
        for (int i = 0; i < size; i++)
        {
            cout << mem[i] << " ";
        }
        cout << endl;
    }
};

int main(){ // 进行访问顺序表
    SeqTable st;
    cout << st.getcapacity() << endl;
    cout << st.getsize() << endl;
    st.setidx(0, 1); // 设置零号元素为1；
    cout << st[0] << endl; // 输出零号元素中的值
    cout << st.getsize() << endl;
    st.setidx(2, 2); // 设置零号元素为1；
    cout << st.getsize() << endl;
    st.print();
    st[10];
    return 0; 
}
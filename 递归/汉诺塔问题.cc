/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-03-31 18:27:01
 * LastEditTime: 2020-03-31 21:29:10
 * Description: 汉诺塔问题求解；
 * tips: 通过运行结果可以发现：总的移动次数为：2^n-1次；n为圆盘个数；
 */

#include <iostream>
using namespace std;
int m = 0; // 移动次数

void move(int disk, char from, char to){
    cout << "移动次数:" << (++m) <<" 把块:" << disk << " 按照如下移动：" <<  from << " --> " << to << endl;
}

// 递归求解汉诺塔
void hanoi(int disks, char from, char to, char assist){
    if (disks == 1) // 递归出口；
    {
        move(disks, from, to); 
        return; 
    }
    //递归子问题；
    hanoi(disks-1, from, assist, to); // n-1个盘子，由A移动到B, 借助辅助塔C；
    move(disks, from, to); // 把第n个盘子，由A移动到C；
    hanoi(disks-1, assist, to, from); // 把n-1个盘子，由B移动到C, 借助辅助塔A；
}

int main(){
    cout << "汉诺塔问题：" << endl;
    int n = 3;
    cout << "汉诺塔圆盘个数：" << n << endl;
    // 创建三个塔；
    char A = 'A';
    char B = 'B';
    char C = 'C';
    // 递归求解汉诺塔，输出移动步骤；
    // n 个盘 从 A 塔移动到 C塔， 借助辅助塔B；
    hanoi(n, A, C, B); // 汉诺塔递归求解；
    return 0;
}
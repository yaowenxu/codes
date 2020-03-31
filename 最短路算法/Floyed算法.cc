/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-03-31 13:19:56
 * LastEditTime: 2020-03-31 13:50:33
 * Description: Floyed 算法
 */

#include <iostream> 
using namespace std; 
#define NUM 7 
#define INF 1000 
int adjmatrix[NUM][NUM];

//返回最小值；
int min(int i, int j){
    int t = i;
    if(j < t){
        t = j;
    }
    return t;
}

void floyed(int s = 1, int e = 5){
    int d[NUM][NUM];
    //进行初始化边界条件
    for(int i = 1; i < NUM; i++){
        for (int j = 1; j < NUM; j++)
        {
            d[i][j] = adjmatrix[i][j];
        }
    }
    //进行dp求解；因为其中存在重叠子问题；使用dp方法，求出所有两点之间的最短路；
    // 枚举中间节点；从0个节点开始尝试
    for(int k = 1; k < NUM; k++){
        for (int i = 1; i < NUM; i++)
        {
            for (int j = 1; j < NUM; j++)
            {
                d[i][j] = min(d[i][k] + d[k][j],d[i][j]); 
            }
        }
    }
    cout << d[s][e] << endl;
}

int main(){
    cout << "最短路算法：" << endl;
    //初始化数据；
    for(int i = 1; i < NUM; i++){
        for(int j = 1; j < NUM; j++){
            if(i == j){
                adjmatrix[i][j] = 0;
            }else{
                adjmatrix[i][j] = INF;
            }
        }
    }
    adjmatrix[1][2] = 7; adjmatrix[1][3] = 9; adjmatrix[1][6] = 14;
    adjmatrix[2][1] = 7; adjmatrix[2][3] = 10; adjmatrix[2][4] = 15;
    adjmatrix[3][1] = 9; adjmatrix[3][2] = 10; adjmatrix[3][4] = 11; adjmatrix[3][6] = 2;
    adjmatrix[4][2] = 15; adjmatrix[4][3] = 11; adjmatrix[4][5] = 6;
    adjmatrix[5][4] = 6; adjmatrix[5][6] = 9;
    adjmatrix[6][1] = 14; adjmatrix[6][3] = 2; adjmatrix[6][5] = 9;
    // Floyed 算法，求解最短路算法；
    floyed();
    return 0;
}
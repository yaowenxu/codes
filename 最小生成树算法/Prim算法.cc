/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-03-29 18:37:40
 * LastEditTime: 2020-03-29 22:03:14
 * Description: prim 算法, 使用集合进行实现，其中数据为博客中数据；算法输出为所选择的边；
 */

#include <iostream>
#include <set>
#include <vector>
using namespace std;
// 使用邻接表表示图
#define NUM 6
#define INF 1000
char vertex[NUM] =  {'A', 'B', 'C', 'D', 'E', 'F'}; // 顶点集合
int adjmatrix[NUM][NUM];

// prim 算法实现，输出所选择的边；
void prim(int s = 0){
    set<int> V;
    set<int> Vnew;
    for(int i = 0; i < NUM; i++){
        V.insert(i);
    }
    Vnew.insert(s); V.erase(s);
    // 循环选取最小边
    while(Vnew.size()!=NUM){
        int min = INF; int es; int et;
        set<int>::iterator vite;
        set<int>::iterator vnewite;
        for(vite = Vnew.begin(); vite!=Vnew.end(); vite++){
            for( vnewite= V.begin(); vnewite!= V.end(); vnewite++){
                if(adjmatrix[*vite][*vnewite] <= min){
                    min = adjmatrix[*vite][*vnewite];
                    es = *vite; et =  *vnewite; // 数组标识
                }
            }
        }
        cout << vertex[es] << " " << vertex[et] << endl;
        V.erase(et);
        Vnew.insert(et);
    }
}

int main(){
    for(int i = 0; i < NUM; i++){
        for(int j = 0; j < NUM; j++){
            adjmatrix[i][j] = INF;
        }
    }
    //初始化图数据
    adjmatrix[0][1] = 6; adjmatrix[0][2] = 1; adjmatrix[0][3] = 5;
    adjmatrix[1][0] = 6; adjmatrix[1][2] = 5; adjmatrix[1][4] = 3;
    adjmatrix[2][0] = 1; adjmatrix[2][1] = 5; adjmatrix[2][3] = 5; 
    adjmatrix[2][4] = 6; adjmatrix[2][5] = 4;
    adjmatrix[3][0] = 5; adjmatrix[3][2] = 5; adjmatrix[3][5] = 2;
    adjmatrix[4][1] = 3; adjmatrix[4][2] = 6; adjmatrix[4][5] = 6;
    adjmatrix[5][2] = 4; adjmatrix[5][3] = 2; adjmatrix[5][4] = 6;
    //prim 算法
    cout << "Prim算法：" << endl; 
    prim();
    return 0;
}
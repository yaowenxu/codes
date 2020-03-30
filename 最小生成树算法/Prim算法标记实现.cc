/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-03-30 15:56:13
 * LastEditTime: 2020-03-30 16:37:04
 * Description: Prim算法，不适用集合来进行实现；使用标记来进行实现；
 */

#include <iostream>
using namespace std;
// 使用邻接表表示图
#define NUM 6
#define INF 1000
char vertex[NUM] =  {'A', 'B', 'C', 'D', 'E', 'F'}; // 顶点集合
int adjmatrix[NUM][NUM];
bool Vnew[NUM]; // 全局变量默认所有的都为false;
int cost[NUM]; // 表示，Vnew中节点，到V节点中的距离；Vnew中的节点使用上述数组进行标记；
int costfrom[NUM]; // 表示cost中最小值来自哪条边

// prim 算法实现，输出所选择的边；
void prim(int s = 0){
    int t = s;
    for (int k = 0; k < NUM-1; k++) // 每次都是确定一条边，当有6个点，则只需要确定 5 条边即可；
    {
        Vnew[t] = true; // 标记t节点已经被访问了；
        cost[t] = 0; 
        // 进行更新 t 到 V 中最短距离；
        for(int i = 0; i < NUM; i++){ 
            if(Vnew[i] != true && adjmatrix[t][i]!=INF && adjmatrix[t][i] < cost[i]){
                cost[i] =  adjmatrix[t][i]; // 更新当前Vnew节点，到V节点之间的距离；
                costfrom[i] = t;
            }
        }
        //选择最小的边对应的节点；
        int min = INF;
        for (int i = 0; i < NUM; i++)
        {
            if(Vnew[i]!=true && cost[i] < min){
                min = cost[i];
                t =  i;
            }
        }
        //输出当前选择的边；
        cout << vertex[costfrom[t]] << " " << vertex[t] << endl;
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
    //初始化cost 数组；
    for (int i = 0; i < NUM; i++)
    {
        cost[i] = INF;
    }
    for (int i = 0; i < NUM; i++)
    {
        costfrom[i] = i; // 当前来自哪条边
    }
    //prim 算法
    cout << "Prim算法（标记法实现）：" << endl; 
    prim();
    return 0;
}
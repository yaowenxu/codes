/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-03-31 16:28:46
 * LastEditTime: 2020-03-31 17:05:04
 * Description: Bellman-Ford算法实现；
 */

#include <iostream> 
using namespace std; 
#define NUM 7 
#define INF 1000 
int adjmatrix[NUM][NUM];
int dist[NUM];
int from[NUM];
int min(int i, int j){
    return (i < j)?i:j; //返回两者中的最小值；
}

void bellman_ford(int s = 2, int e = 5){
    dist[s] = 0;
    from[1] = 1;
    // O(nm) m为边的个数；
    for (int k = 1; k < NUM-1; k++) // 6个点，总共循环5次；
    {
        for (int u = 1; u < NUM; u++)
        {
            for (int v = 1; v < NUM; v++)
            {
                if (adjmatrix[u][v] != INF) // u,v之间存在
                {
                    int tmp = min(dist[v], dist[u]+adjmatrix[u][v]);
                    if(tmp != dist[v]){
                        from[v] = u; // 更新路径；
                    }
                    dist[v] = tmp;
                }
            }
        }
    }
    int flag = false;
    for (int u = 1; u < NUM; u++)
    {
        for (int v = 1; v < NUM; v++)
        {
            if (adjmatrix[u][v] != INF) // u,v之间存在
            {
                int tmp = min(dist[v], dist[u]+adjmatrix[u][v]);
                if(tmp != dist[v]){
                    flag = true;
                    break;
                }
                dist[v] = tmp;
            }
        }
    }
    if (flag)
    {
        cout << "存在负环！" << endl;
    }else{
        cout << "最短路长度为：" << dist[e] << endl;
    }
    cout << "最短路径：" << endl;
    int p = e;
    cout << e; 
    while (from[p] !=  p)
    {
         p = from[p];
         cout << "-" << p ;
    }
    cout << endl;
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
    // bellman_ford 算法，求解最短路算法；
    for (int i = 0; i < NUM; i++)
    {
        dist[i] = INF;
    }
    for (int i = 0; i < NUM; i++)
    {
        from[i] = i; // 确定顶点之间的关系
    }
    bellman_ford();
    return 0;
}
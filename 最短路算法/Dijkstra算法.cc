/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-03-30 13:23:19
 * LastEditTime: 2020-03-30 15:01:31
 * Description: Dijkstra 算法实现；
 */

#include <iostream>
using namespace std;
#define NUM 7
#define INF 1000
int adjmatrix[NUM][NUM];
int dist[NUM]; //距离
bool visit[NUM]; // 是否访问
int from[NUM]; // 上一个点来自哪儿；

void Dijkstra(int s = 1, int d =  5){
    dist[s] = 0;
    from[s] = s;
    int t = s; // 每次访问的节点
    for(int k = 1; k < NUM; k++){
        cout << "visit:" << t << endl;
        visit[t] = true;
        // 更新该周边节点的最小距离；
        for (int i = 1; i < NUM; i++){
            if(adjmatrix[t][i]==INF){
                continue;
            }
            if(dist[t]+adjmatrix[t][i] < dist[i] && visit[i]!= true){
                dist[i] = dist[t]+adjmatrix[t][i];
                from[i] = t;
            }
        }
        // 找到下一个要访问的节点；
        int min = INF; 
        for(int i = 1; i < NUM; i++){
            if(dist[i] < min && visit[i] != true){
                min = dist[i];
                t = i;
            }
        }
    }
    //打出从起始节点到目的节点之间的路径；
    int p = d;
    cout << d; 
    while (visit[p] !=  p)
    {
         p = from[p];
         cout << "-" << p ;
    }
    cout << endl;
    //print dist;
    cout << "dist:" << endl;
    for (int i = 1; i < NUM; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
    //print visit
    cout << "visit:" << endl;
    for (int i = 1; i < NUM; i++)
    {
        cout << visit[i] << " ";
    }
}

int main(){
    cout << "最短路算法：" << endl;
    //初始化数据；
    for(int i = 1; i < NUM; i++){
        for(int j = 1; j < NUM; j++){
            adjmatrix[i][j] = INF;
        }
    }
    adjmatrix[1][2] = 7; adjmatrix[1][3] = 9; adjmatrix[1][6] = 14;
    adjmatrix[2][1] = 7; adjmatrix[2][3] = 10; adjmatrix[2][4] = 15;
    adjmatrix[3][1] = 9; adjmatrix[3][2] = 10; adjmatrix[3][4] = 11; adjmatrix[3][6] = 2;
    adjmatrix[4][2] = 15; adjmatrix[4][3] = 11; adjmatrix[4][5] = 6;
    adjmatrix[5][4] = 6; adjmatrix[5][6] = 9;
    adjmatrix[6][1] = 14; adjmatrix[6][3] = 2; adjmatrix[6][5] = 9;
    // 初始化算法依赖结构体；
    for (int i = 1; i < NUM; i++){
        dist[i] = INF;
    }
    for (int i = 1; i < NUM; i++){
        visit[i] = false;
    }
    for (int i = 1; i < NUM; i++){
        from[i] = i;
    }
    // Dijkstra 算法求解；
    Dijkstra();
    return 0;
}
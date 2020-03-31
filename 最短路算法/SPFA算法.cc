/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-03-31 17:38:21
 * LastEditTime: 2020-03-31 18:04:37
 * Description: SPFA 算法， shortest path faster algorithm
 */
#include <iostream> 
#include <queue>
using namespace std; 
#define NUM 7 
#define INF 1000 
int adjmatrix[NUM][NUM];
int dist[NUM];
int from[NUM];
int min(int i, int j){
    return (i < j)?i:j; //返回两者中的最小值；
}
bool inqueue[NUM]; // 标记节点是否位于队列中；
queue<int> que; // 队列中记录已经被更新的节点；
int cnt[NUM]; // 用于记录节点入队次数是否大于n,如果大于n表示出现负环的情况；

// 单源最短路径算法；
void SPFA(int s = 1, int e = 5){
    que.push(s);
    dist[s] = 0;
    from[s] = s;
    inqueue[s] = true; //标记节点在队列中；
    cnt[s]++;
    while (!que.empty()) // 当队列不空时就继续循环；
    {
        int u = que.front(); que.pop(); // 弹出队首元素；
        inqueue[u] = false; // 标记当前元素没有在队列中；
        for (int v = 1; v < NUM; v++)
        {
            if(adjmatrix[u][v] == INF) continue; // 不存在边；
            int tmp = min(dist[v], dist[u]+ adjmatrix[u][v]);
            if (tmp!=dist[v]){
                dist[v] = tmp;
                from[v] = u;
                if(!inqueue[v]){
                    que.push(v);
                    inqueue[v] = true;
                    if (cnt[v]>=NUM)
                    {
                        cout << "存在负环！" << endl;
                        return;
                    }
                    cnt[v]++; // 增加进队次数；
                }
            }
        }
    }
    // 最短路更新完毕，输出结果；
    cout << "最短路长度为：" << dist[e] << endl;
    cout << "最短路径：" << endl;
    int p = e;
    cout << e; 
    while (from[p] !=  p)
    {
         p = from[p];
         cout << "-" << p;
    }
    cout << endl;
}

int main(){
    cout << "SPFA 最短路算法：" << endl;
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
    SPFA();
    return 0;
}
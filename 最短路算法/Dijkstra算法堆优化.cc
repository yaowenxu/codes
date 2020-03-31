/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-03-30 15:06:58
 * LastEditTime: 2020-03-31 17:03:45
 * Description: Dijkstra算法，堆优化版本；堆优化的版本只是在寻找当前dist[i]以确定下一即将被遍历的节点过程，中进行了堆排序优化；
 * tips: 本题中使用优先队列来进行实现；
 */

#include <iostream>
#include <queue>
using namespace std;
#define NUM 7
#define INF 1000
int adjmatrix[NUM][NUM];
int dist[NUM]; //距离
bool visit[NUM]; // 是否访问
int from[NUM]; // 上一个点来自哪儿；
// 优先队列中的元素
struct node {
    int p; // 当前节点名称；
    int dist; // 距离当前节点距离；
    bool operator< (const struct node &e) const{
        return dist > e.dist; //小的优先级越高;
    }
};
priority_queue<struct node> pqueue;
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
                struct node e;
                e.p = i;
                e.dist = dist[i];
                pqueue.push(e);
            }
        }
        // 找到下一个要访问的节点；- 此处进行堆优化；
        while (!pqueue.empty())
        {
            if(visit[pqueue.top().p]!=true){ // 如果队列中出现的节点是已经被访问过的节点，则跳过
                t = pqueue.top().p;
                pqueue.pop();
                break;
            }
            pqueue.pop();
        }
    }
    //打出从起始节点到目的节点之间的路径；
    int p = d;
    cout << d; 
    while (from[p] !=  p)
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
    struct node n1; n1.dist = 10;
    struct node n2; n2.dist = 1;
    pqueue.push(n1);
    pqueue.push(n2);
    cout << pqueue.top().dist << endl;
    exit(0);
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
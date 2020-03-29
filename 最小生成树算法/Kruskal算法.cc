/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-03-29 21:58:15
 * LastEditTime: 2020-03-29 22:01:08
 * Description: kruskal 算法，使用数组进行进行存储边并进行排序；从最小边开始选择；遍历边列表，选择位于两颗树的边输出；
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

struct edge{
    int u;
    int v;
    int val;
};

bool cmp(const struct edge &e1, const struct edge &e2){
        return e1.val < e2.val;
}

//kruskal 算法
void kruskal(){
    int bitmap[NUM]; //用此判断两个边是不是在同一集合中；
    for(int i = 0; i < NUM; i++){
        bitmap[i] = i;
    }
    vector<struct edge> edgevector;
    for(int i = 0; i < NUM; i++){
        for (int j = i+1; j < NUM; j++)
        {
            struct edge e;
            e.u = i; e.v = j; e.val = adjmatrix[i][j];
            if(e.val != INF){
                edgevector.push_back(e);
            }
        }
    }
    sort(edgevector.begin(), edgevector.end(), cmp);
    // sort(edgevector.begin(), edgevector.end(), [](const struct edge &e1, const struct edge &e2){
    //     return e1.val < e2.val; //返回有序数据
    // });
    for(int i = 0; i < edgevector.size(); i++){
        int u =  edgevector[i].u;
        int v =  edgevector[i].v;
        if(bitmap[u] != bitmap[v]){
            int t =  bitmap[v]; // 保存变量，放置中间被修改；
            for(int j = 0; j < NUM; j++){
                if(bitmap[j] ==  t){
                    bitmap[j] = bitmap[u]; // 加入到同一树中
                }
            }
            cout << vertex[u] << " " << vertex[v] << endl;
        }
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
    // Kruskal 算法实现：
    cout << "kruskal算法：" << endl;
    kruskal();
    return 0;
}
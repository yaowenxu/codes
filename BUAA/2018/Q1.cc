// 最长折线

// 可将所有的选段看作为图中的点；线段看作为有向边；从而形成森林；节点是平面坐标；
// 先找到所有的树根，为入度为0的点，然后求最大的树高，输出树高和树根；
// https://blog.csdn.net/cgsdfc/article/details/113877174

#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef pair<int, int> Point; // 定义点类型；
map<Point, int> in; // 用于记忆节点的入度；
map<Point, vector<Point> > adj; // 创建邻接矩阵；

void DFS(Point p, int len, int& maxlen){
    if (adj[p].size() == 0) // 当前节点没有了出度；
    {
        if (len >= maxlen)
        {
            maxlen = len;
        }
        return;
    }else{
        for (int i = 0; i < adj[p].size(); i++)
        {
            DFS(adj[p][i], len+1, maxlen); // 进一步递归；
        }
    }
}

int main(){
    freopen("Q1.in", "r", stdin); // 重定向标准输入到文件；
    int n = 0;

    while(scanf("%d", &n)!=EOF){
        // 创建入度索引；
        in.clear(); // 进行初始化；
        adj.clear(); 

        for (int i = 0; i < n; i++)
        {
            // 进行读入线段左端点；
            int leftx, lefty;
            scanf("%d %d", &leftx, &lefty);
            Point left(leftx, lefty);
            if (in.find(left) == in.end())
            {
                in[left] = 0; // 进行初始化节点；
            }
            // 进行读入线段右端点；
            int rightx, righty;
            scanf("%d %d", &rightx, &righty);
            Point right(rightx, righty);
            if (in.find(right) != in.end())
            {
                in[right]++;
            }else{
                in[right] = 1; // 进行初始化入度；
            }

            if (adj.find(left) == adj.end())
            {
                adj[left] = vector<Point>();
                adj[left].push_back(right); // 将自己的节点加入邻接矩阵；
            }else{
                adj[left].push_back(right); // 进行建立邻接矩阵；
            }
            if (adj.find(right) == adj.end())
            {
                adj[right] = vector<Point>(); // 进行初始化点的位置；
            }
        }

        // 起始点；
        Point startp;
        int reslen = 0;

        // 进行对每个树进行深度优先搜索；遍历每个入度为0的点，找出最长树高；
        for (auto it = in.begin(); it != in.end(); it++)
        {
            auto p = it->first; // 对当前点记性优先搜索；
            if (it->second == 0)
            { 
                int maxlen = 0;

                // 进行优先搜索；
                DFS(p, 0, maxlen); // 并更新最大长度；

                if (maxlen >=  reslen)
                {
                    reslen = maxlen;
                    startp = p;
                }
            }
        }
        cout << reslen << " " << startp.first << " " << startp.second << endl; // 进行输出结果；
    }

    return 0;
}
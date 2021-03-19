#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

// 简单的树的遍历，我比较喜欢使用map来进行模拟树，而不是指针；
struct Node{
    int id;
    int first; // 第一个；
    int second; // 第二个孩子；
    int third; // 第三个；
    int count; // 计算当前的叉数
};

map<int, Node> id2node; // 建立映射关系；
int cnt = 0; // 表示当前遍历的顺序；
int maxid = -1;
int maxcnt = 0;
int maxchildnum = 0;

void FrontSearch(int id){
    cnt ++; // 递增遍历顺序；

    if (id2node.find(id) == id2node.end())
    {
        return; // 当前节点为叶子节点；
    }

    // 进行前序遍历；
    if (id2node[id].count > maxchildnum && cnt != 1) // 当 cnt == 1时；为树根，需要跳过；
    {
        maxchildnum = id2node[id].count; // 树枝的叉数；
        maxcnt = cnt;
        maxid = id;
    }

    if (id2node[id].first != -1)
    {
        FrontSearch(id2node[id].first);
    }

    if (id2node[id].second != -1)
    {
        FrontSearch(id2node[id].second);
    }
    
    if (id2node[id].third != -1)
    {
        FrontSearch(id2node[id].third);
    }
}

int main(){
    freopen("Q2.in", "r", stdin); // 进行重定向输入到文件；
    int n = 0;
    while (scanf("%d", &n)!=EOF)
    {
        id2node.clear(); // 情况；
        cnt = 0; // 表示当前遍历的顺序；
        maxid = -1;
        maxcnt = 0;
        maxchildnum = 0;
        int first = true;
        int rootid = -1;
        for (int i = 0; i < n; i++)
        {
            Node node;
            node.count = 0;
            scanf("%d %d %d %d", &node.id, &node.first, &node.second, &node.third);
            if (first)
            {
                rootid = node.id;
                first = false; // 第一个点要记录根节点；
            }
            if (node.first != -1)
            {
                node.count ++;
            }
            if (node.second != -1)
            {
                node.count ++;
            }
            if (node.third != -1)
            {
                node.count ++;
            }
            id2node[node.id] = node; // 记录；
        }

        // 三叉树的前序遍历；
        FrontSearch(rootid);
        cout << maxid << " " << maxcnt << endl;
    }
    return 0;
}
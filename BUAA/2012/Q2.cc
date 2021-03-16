// 小岛面积；
// 整体程序，通过一次循环遍历，找出边界和小岛中的点。
// 然后判断该点是否是小岛面积。
// 其中有一个题目中未说明：如果两块地不相连是否还能认为是小岛的面积。
// 编译命令：c++ -std=c++11 Q2.cc -o out ; ./out ; rm out 

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct Node
{
    int i;
    int j;
    Node(int x, int y)
    { // 进行emplace函数的使用；
        i = x;
        j = y;
    }
}; // 表示每个小岛0；

int main()
{
    freopen("Q2.in", "r", stdin); // 进行重定向到文件；
    int size = 0;
    while (scanf("%d", &size) != EOF)
    { // 进行确定数组长度；
        vector<Node> nodeq;                    // 小岛；使用到数组，模拟队列操作；
        vector<vector<int>> bound(size, vector<int>(4, -1)); // 进行初始化flag；
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int land = -1;
                scanf("%d", &land);
                // 进行寻找小岛边界；
                if (land == 1)
                {
                    // i下边界；0
                    if (bound[i][0] == -1)
                    {
                        bound[i][0] = j;
                    }
                    bound[i][1] = j; // 进行更新 i 上界；
                    if (bound[j][2] == -1)
                    {
                        bound[j][2] = i;
                    }
                    bound[j][3] = i; // 进行更新j上界；
                }
                else
                {
                    if (i != 0 && j != size - 1 && j != 0 && i != size - 1)
                    {
                        nodeq.emplace_back(i, j); // 进行填充带判断land队列；
                    }
                }
            }
        }
        // 进行计算面积；
        int area = 0; // 表示当前面积的为0；
        for (auto it = nodeq.begin(); it != nodeq.end(); it++)
        {
            int i = (*it).i;
            int j = (*it).j;
            // cout << bound[i][0] << " " << bound[i][1] << endl;
            if (bound[i][0] < j && bound[i][1] > j && bound[j][2] < i && bound[j][3] > i)
            {
                // cout << i << " " << j << endl; // 打印出小岛中的点；
                area ++; // 此时表示此为小岛；
            }
        }
        cout << area << endl;
    }
    return 0;
}

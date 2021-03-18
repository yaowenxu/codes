// 模拟鼠标点击窗口；

#include <cstdio>
#include <deque>
#include <iostream>

using namespace std;

struct Window{
    int id;
    int rightdownx;
    int rightdowny;
    int leftupx;
    int leftupy;
};

// 题目保证所有的输入内容都是整数；坐标均以屏幕左下角为原点；
// 通过一次遍历解决问题；
int main(){
    freopen("Q2.in", "r", stdin); // 进行重定向标准输入到文件。
    int n = 0;
    while (scanf("%d", &n)!=EOF)
    {
        deque<Window> windq; // 存储窗口的双端队列；
        for (int i = 0; i < n; i++)
        {
            Window win;
            scanf("%d", &win.id);
            scanf("%d %d %d %d", &win.rightdownx, &win.rightdowny, &win.leftupx, &win.leftupy);
            windq.push_back(win);
        }
        int m = 0;
        scanf("%d", &m); // 表示后续的m行点击；
        for (int i = 0; i < m; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            // 进行遍历当前队列；
            for (auto it = windq.begin(); it != windq.end(); it++)
            {
                Window t = *it;
                // 进行更新窗口顺序；
                if (x >= it->leftupx && x <=  it->rightdownx && y <= it->leftupy && y >= it->rightdowny)
                {
                    windq.erase(it);
                    windq.push_front(t);
                    break;
                }
            }
        }
        // 进行遍历输出结果；
        bool first = true;
        for (auto it = windq.begin(); it != windq.end(); it++)
        {
            if (first)
            {
                first = false;
            }else{
                cout << " ";
            }
            cout << it->id;
        }
        cout << endl;
    }
    return 0;
}
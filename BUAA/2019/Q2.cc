#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <deque>
using namespace std;

// 题目标注旅客不会有相同优先级；本答案使用 map 来进行求解；使用树来进行辅助思考，未使用搜索；

struct Person
{
    int aim; // 旅客目的地；
    int prio; // 优先级；
};

bool CMP(const Person& a, const Person& b){
    return a.prio < b.prio;
}

int main(){
    freopen("Q2.in", "r", stdin); // 重新定向到标准输入到文件；
    int n = 0;
    while(scanf("%d", &n)!=EOF){
        int root = true;
        int start = -1; // 表示开始
        int end = -1; // 表示结束
        int rootid = -1;
        map<int, int> famap;
        for (int i = 0; i < n; i++)
        {
            int fa;
            int s1, s2, s3;
            scanf("%d %d %d %d", &fa, &s1, &s2, &s3); // 进行读入数据；
            if (root)
            {
                famap[fa] = -1;
                start = fa;
                rootid = fa;
                root = false;
            }
            if (s1 != -1)
            {
                famap[s1] = fa;
            }
            if (s2 != -1)
            {
                famap[s2] = fa;
            }
            if (s3 != -1)
            {
                famap[s3] = fa;
            }
        }
        // 进行输入旅客；
        vector<Person> vec;
        int m = 0;
        scanf("%d", &m); // 旅客人数
        for (int i = 0; i < m; i++)
        {
            Person p;
            scanf("%d %d", &p.aim, &p.prio);
            vec.push_back(p);
        }
        // 进行按照优先级排序；
        sort(vec.begin(), vec.end(), CMP); // 进行比较相邻两者之间的顺序；
        Person self;
        self.aim = rootid;
        vec.push_back(self); // 最后一个任务是回到终点；
        for (auto it = vec.begin(); it != vec.end(); it++)
        {
            // 进行输出vec中的内容；
            auto p =  *it;
            end =  p.aim;
            deque<int> first; // 从 start 回到根节点；
            deque<int> second; // 从 end 回到根节点；
            int st = start;
            int et = end;
            while(famap[st] != -1){
                first.push_front(famap[st]);
                st = famap[st];
            }
            while(famap[et] != -1){
                second.push_front(famap[et]);
                et = famap[et];
            }

            if (first.size() == 0)
            {
                for (auto out2 = second.begin(); out2 != second.end(); out2++)
                {
                    cout << *out2 <<  " ";
                }
            }

            if (first.size()!=0)
            {
                if (second.size() == 0)
                {
                    if (first.size() != 1)
                    {
                        for (auto out1 = first.rbegin(); out1 != first.rend()-1; out1++) // 此处减一是为了，不输出根节点；
                        {
                            cout << *out1 << " ";
                        }
                    }
                }else{
                    auto it1 = first.begin();
                    auto it2 = second.begin();
                    int same = -1;
                    while(it1 != first.end() && it2 != second.end() && *it1 == *it2){
                        same = *it1;
                        it1 ++;
                        it2 ++;
                        first.pop_front();
                        second.pop_front();
                    }
                    // 输出第一段；
                    for (auto out1 = first.rbegin(); out1 != first.rend(); out1++) // 此处使用逆向迭代器；
                    {
                        cout << *out1 << " ";
                    }
                    
                    if (same != -1)
                    {
                        cout << same << " ";
                    }

                    auto out2 = it2;
                    while (out2 != second.end())
                    {
                        cout << *out2 << " ";
                        out2 ++;
                    }
                }
            }
            
            cout << end << endl;
            start = end; // 进行重新更新起点；
        }
    }
    return 0;
}
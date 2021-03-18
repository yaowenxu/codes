// 枚举输出；字符串解析题，需要判断字符串如何存储；和数字的解析；
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main(){
    freopen("Q2.in", "r", stdin); // 进行重定向输入到文件；
    char buffer[1000000]; // 输入缓冲区；
    vector<char> itembuf;
    while (fgets(buffer, 1000000, stdin)!=NULL)
    {
        int cnt = 0;
        int i = 0;
        bool procit = false;
        while(buffer[i] != '\0'){
            char c = buffer[i]; // 进行处理字符；
            if (c == '{') // 进行开始处理字符串；
            {
                procit = true;
                i++;
                continue;
            }
            if (procit)
            {
                if (c != ',' && c!='}')
                {
                    if (c != ' ')
                    {
                        itembuf.push_back(c); // 进行加入缓冲区；
                    }
                }else{
                    if (itembuf.size()!=0)
                    {
                        //进行处理
                        itembuf.push_back('\0');
                        // 进行处理；
                        vector<char> tmp;
                        int first = true; // 第一阶段；
                        int tnum = 0;
                        bool updatetnum = false;
                        for (int j = 0; j < itembuf.size()-1; j++)
                        {
                            // 进行处理数组；
                            int tc =  itembuf[j];
                            // cout << tc << endl;
                            if (tc != '=') // 今天找出字母值；
                            {
                                if (first)
                                {
                                    tmp.push_back(tc); // 进行加入到数组中；
                                }else{
                                    tnum *= 10;
                                    tnum +=  tc - '0';
                                    updatetnum = true; // 标记已经修改了tnum;
                                }
                                /* code */
                            }else{
                                first = false;  // 进行第二阶段；
                                tmp.push_back('\0');
                            }
                        }
                        tmp.push_back('\0');
                        cout << tmp.data();
                        cout << " "; //进行
                        if (updatetnum)
                        {
                            cnt = tnum;
                            cout << tnum << endl;
                            cnt ++;
                        }else{
                            cout << cnt << endl;
                            cnt ++;
                        }
                        itembuf.clear(); // 进行清空；
                    }
                }
            }
            if (c == '}'){
                procit = false;
            }
            ++i;
        }
    }
    return 0; 
}
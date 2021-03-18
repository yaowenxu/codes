// 统计词语，字符串处理；
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

bool isabc(char c){
    if (c >= 'a' && c <= 'z'){
        return true;
    }
    if (c >= 'A' && c <= 'Z')
    {
        return true;
    }
    return false;
}

// 题目保证所有的输入都是小写；
int main(){
    freopen("Q3.in", "r", stdin); // 进行重定向文件到标准输入；
    set<string> resultset; // 表示结果的集合；
    char buffer[100000];
    memset(buffer, 0, 100000); // 表示缓存中的内容；
    while (fgets(buffer, 100000, stdin) != NULL)
    {
        vector<char> vec;
        int i = 0;
        while (buffer[i] != '\0')
        {
            int c = buffer[i];
            if(isabc(c)){
                vec.push_back(c);
            }else{
                if (vec.size() != 0)
                {
                    vec.push_back('\0');
                    string str(vec.data()); //进行转换为string;
                    resultset.insert(str); // 进行将字符串添加进入set;
                    vec.clear();
                }  
            }
            i ++; //进行自增；
        }
    }
    for (auto it = resultset.begin(); it != resultset.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}
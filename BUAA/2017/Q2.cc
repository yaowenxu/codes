// 查找未定义变量；
// 编译命令: c++ Q2.cc -std=c++11 -o out; ./out ; rm out
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
using namespace std; // 使用命名空间；

bool isVarbegin(char c); // 判断是否是变量的开头
bool isinVar(char c); // 判断是否是变量的后半部分

// 题目中表明不存在多词变量的情况，可以不处理；题目中表明：第一行的C语言的语法是规范的; 第二句是基本的变量运算语句。
// 如果没有上述限定，题目将会更为复杂；
int main(){
    freopen("Q2.in", "r", stdin); // 进行重定向输入到文件；
    string line1;
    getline(cin, line1);
    string line2;
    getline(cin, line2);

    // 进行处理第一行；解析变量；
    set<string> varset; // 将当前声明的变量加入集合中；
    vector<char> buf;
    bool linebegin = true; // 判断当前是否在首行；用于处理变量类型；
    bool parse_var = false; // 判断当前是否正在解析变量名称，位于等于号前面，指导遇到，和 ；时；状态改变；
    bool front  = true; // 表示正在解释变量的前一部分；
    for (int i = 0; i < line1.size(); i++)
    {
        char c =  line1[i];
        if (linebegin) // 进行处理行首的情况；
        {
            if (parse_var)
            {
                if (isinVar(c))
                {
                    buf.push_back(c);
                }else{
                    // 找到了第一个变量名称；
                    buf.push_back('\0');
                    // cout << buf.data() << endl;
                    buf.clear();
                    linebegin = false; // 从当前开始已经不是在行首了；
                    parse_var = false; // 停止变量解析阶段；
                }
            }else{
                if (isVarbegin(c))
                {
                    buf.push_back(c);
                    parse_var = true;
                }
            }
        }
        if (c == ';') // 存在下一行的情况； int a; int b;
        {
            if(buf.size()!= 0){
                buf.push_back('\0');
                // cout << buf.data() << endl;
                string str(buf.data());
                buf.clear();
                varset.insert(str);
            }
            linebegin = true;
            parse_var = false;
            front = true;
        }
        if (!linebegin){
            if (c == ',')
            {
                if (buf.size() != 0)
                {
                    buf.push_back('\0');
                    // cout << buf.data() << endl;
                    string str(buf.data());
                    buf.clear();
                    varset.insert(str);
                }
                front = true;
                parse_var = false;
            }
        }
        if (!linebegin){ // 处理不是行首的情况，进行解析变量；
            if (front) // 表示当前正在解释变量的前一部分；
            {
                if (parse_var)
                {
                    if (isinVar(c))
                    {
                        buf.push_back(c);
                    }else{
                        // 找到一个变量名称；
                        buf.push_back('\0');
                        // cout << buf.data() << endl;
                        string str(buf.data());
                        buf.clear();
                        varset.insert(str);
                        buf.clear();
                        parse_var = false; // 停止变量解析阶段；
                        front = false;
                    }
                }else{
                    if (isVarbegin(c))
                    {
                        buf.push_back(c);
                        parse_var = true;
                    }
                }
            }
        }
    }

    // 进行处理第二行；
    buf.clear();
    parse_var = false;
    for (int i = 0; i < line2.size(); i++)
    {
        char c = line2[i]; 
        if (parse_var)
        {
            if (isinVar(c))
            {
                buf.push_back(c);
            }else{
                // 找到一个变量；
                buf.push_back('\0');
                string str(buf.data());
                buf.clear();
                parse_var = false;
                if(varset.count(str) == 0){
                    cout << str << " ";
                }
            }
        }else{
            if (isVarbegin(c))
            {
                buf.push_back(c); // 进行添加到buffer之中；
                parse_var = true; // 进行解析变量；
            }
        }
    }

    // 输出换行；
    cout << endl;
    
    return 0;
}

bool isVarbegin(char c){ //表示是变量的开头；
    if (c >= 'a' && c <= 'z')
    {
        return true;
    }
    if (c == '_')
    {
        return true;
    }
    if (c >=  'A' && c <= 'Z'){
        return true;
    }
    return false; 
}

bool isinVar(char c){ //表示该字符是变量中间的部分；
    if (c >= 'a' && c <= 'z')
    {
        return true;
    }
    if (c == '_')
    {
        return true;
    }
    if (c >=  'A' && c <= 'Z'){
        return true;
    }
    if (c >= '0' && c <= '9'){
        return true;
    }
    return false; 
}
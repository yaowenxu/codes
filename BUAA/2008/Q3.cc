// 编译命令：
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

void out_to_file(FILE *file, int line, const char *str)
{
    fprintf(file, "%d : %s", line, str);
}

bool issame(char a, char b){
    // 如果是大写，转为小写；
    if (a >= 'A' && a <= 'Z'){
        a = a - 'A' + 'a';
    }
    if (b >= 'A' && b <= 'Z')
    {
        b = b - 'A' + 'a'; 
    }
    return a == b; // 进行返回相等值；
}

// 字符串匹配不区分大小写；输出所有匹配的字符串。输出行号和字符串到文件；其中有一个以中括号匹配的字符串；
int main()
{
    freopen("Q3.in", "r", stdin);
    // 进行分析输入字符串；
    string str; // 进行临时存储字符串；
    while (!cin.eof())
    {
        FILE *infile = fopen("string.in", "r");   //以只读模式，打开文件；
        FILE *outfile = fopen("string.out", "w"); // 以写模式打开文件；
        cin >> str;
        set<char> inset; // 所有位于set中的字符都是可以匹配的；
        int begin = false;
        set<char> tmpset;
        int front = str.size(); // 记录  [ 的位置；
        int end = str.size(); // 记录 ] 的位置；
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '[')
            {
                begin = true; // 进行插入字符串；
                front = i;    // 记录前一部分结束的值；
                continue;
            }
            if (str[i] == ']')
            {
                begin = false; // 停止插入字符串；
                end = i;       // 记录后一部分开始的值；
            }
            if (begin)
            {
                tmpset.insert(str[i]); // 进行插入字符串；
            }
        }
        if (begin == false && tmpset.size() != 0)
        {
            inset.swap(tmpset); // 进行交换内存；
        }
        //进行从文件中读入字符串
        char c; // 依次读入字符串，进行匹配；
        vector<char> input;
        vector<char> buffer; // 字符结构；
        int line_no = 1; // 进行计算行数；
        while (fscanf(infile ,"%c", &c) != EOF)
        {
            input.push_back(c); // 进行保存；
        }
        for (int i = 0; i < input.size();)
        {
            if (input[i] == '\n')
            {
                line_no ++; // 进行增加行数；
            }
            int out = true;
            // 进行子遍历；
            if (issame(input[i], str[0]))
            {
                int now = i;
                // 进行遍历前一部分；
                for (int j = 0; j < front; j++)
                {
                    if (!issame(input[now], str[j]))
                    {
                        out = false;
                        buffer.clear();
                        now = i;
                        break;
                    }
                    buffer.push_back(input[now]);
                    now++;
                }
                // 进行通配符中的匹配；
                if( now != i){
                    if(inset.size() != 0){
                        if (!inset.count(input[now])) // 如果通配符没有找到
                        {
                            out = false;
                            buffer.clear();
                            now = i;
                        }else{
                            buffer.push_back(input[now]); // 进行加入到缓冲区中；
                            now ++;
                        }
                    }
                }
                // 进行通配符后面的匹配；
                if (now != i)
                {
                    for (int j = end+1; j < str.size(); j++)
                    {
                        if (!issame(input[now], str[j]))
                        {
                            out = false;
                            buffer.clear();
                            now = i;
                            break;
                        }
                        buffer.push_back(input[now]); // 进行添加进入输出缓冲区；
                        now++;
                    }
                }
                // 进行判断，当前是否需要输出；
                if (out)
                {
                    buffer.push_back('\0'); // 进行输出；
                    cout << line_no << " : " << buffer.data() << endl;
                    out_to_file(outfile, line_no, buffer.data());
                    i = now;
                    buffer.clear(); // 进行清空缓冲区；
                }else{
                    i++;
                }
            }
            i++;
        }
        fclose(infile);
        fclose(outfile);
    }
    return 0;
}
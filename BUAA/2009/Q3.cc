// 字符串查找删除; 具体题意不是很明确，此为参考答案；
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

bool is_Same(char a, char b){
    // 全转换为大写；
    if (a >='a' && a <= 'z')
    {
        a =  a - 'a' + 'A'; // 进行大小写转换；
    }
    if (b >= 'a' && a <= 'z')
    {
        b =  b - 'a' + 'A'; // 进行大小写转换；
    }
    return a == b;
}

int main(){
    freopen("Q3.in", "r", stdin); // 重定向输入到文件；
    char buffer[100]; // 进行声明缓冲区，用于存储字符串；
    memset(buffer, 0, 100);
    FILE* infile = fopen("filein.txt", "r"); // 打开输出文件；
    FILE* outfile = fopen("fileout.txt", "w"); // 打开输入文件；
    // 尝试使用eof进行求解问题；
    
    char input[100];
    memset(input, 0, 100); 
    scanf("%s", input);
    while(fgets(buffer, 100, infile)!=NULL){
        int i = 0;
        bool out = false; // 表示当前空格是否需要输出；
        while(buffer[i]!='\0'){
            if(buffer[i] == ' ')
            {
                if(out)
                {
                    cout << buffer[i];
                    fprintf(outfile, "%c", buffer[i]);
                    i++;
                    continue;
                }else{
                    i++;
                    continue;
                }
            }else{
                out = true; // 表示之后需要输出空格。
            }
            if (is_Same(buffer[i], input[0])) // 发现待匹配元素；
            {
                bool jump = true;
                int tindex = i+1; // 当前下标；
                for (int j = 1; j < strlen(input); j++)
                {
                    //进行匹配；
                    if (buffer[tindex] == '\0')
                    {
                        jump = false;
                        break;
                    }
                    if (!is_Same(buffer[tindex], input[j]))
                    {
                        jump = false;
                        break;
                    }
                    tindex ++; // 进行增加序列；
                }
                if(jump){
                    i = i + strlen(input); // 进行跳过;
                }else{
                    cout << buffer[i];
                    fprintf(outfile, "%c", buffer[i]);
                    i++; // 进行增加下标；
                }
            }else{
                cout << buffer[i];
                fprintf(outfile, "%c", buffer[i]);
                i++; // 进行增加下标；
            }
        }
    }
}
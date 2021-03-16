// 编译命令：c++ -std=c++11 Q3.cc -o out ; ./out ; rm out
#include <cstdio>
#include <iostream>
using namespace std;

bool is_little_char(char c){
    return (c >= 'a') && (c <= 'z'); // 小写字母
}

bool is_big_char(char c){
    return (c >= 'A') && (c <= 'Z'); // 大写字母
}

bool is_num(char c){
    return (c >= '0') && (c <= '9'); // 数字；
}

int main(){
    freopen("Q3.in", "r", stdin);
    while(!cin.eof()){
        string str;
        cin >> str;
        
        for (int i = 0; i < str.size(); i++)
        {
            // 进行展开；
            if(str[i] == '-' && i == 0){
                cout << '-';
                continue;
            }

            // 判断是否超过字符串范围；
            if(str[i] == '-' && i+1 <str.size()){
                if (is_little_char(str[i-1]) && is_little_char(str[i+1]))
                {
                    for (int j = 1; j < str[i+1]-str[i-1]; j++)
                    {
                        cout << char(str[i-1]+j);
                    }
                    continue;
                }
                if (is_big_char(str[i-1]) && is_big_char(str[i+1]))
                {
                    for (int j = 1; j < str[i+1]-str[i-1]; j++)
                    {
                        cout << char(str[i-1]+j);
                    }
                    continue;
                }
                if (is_num(str[i-1]) && is_num(str[i+1]))
                {
                    for (int j = 1; j < str[i+1]-str[i-1]; j++)
                    {
                        cout << char(str[i-1]+j);
                    }
                    continue;
                }
                cout << str[i];
                continue;
            }
            
            cout << str[i];
        }
        cout << endl;
    }
    return 0;
}
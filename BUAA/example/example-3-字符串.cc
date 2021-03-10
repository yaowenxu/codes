// 编译操作：c++ -std=c++11 example-3-字符串.cc -o out ; ./out; rm out
// C语言字符串接口练习；

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
    
    // strcpy
    char str1[14] = "runoob";
    char str2[14] = "google";
    char str3[14];
    int len;

    strcpy(str3, str1);
    cout << str3 << endl;
    cout << "len1:" << strlen(str1) << endl;
    cout << "len2:" << strlen(str2) << endl;
    strcat(str3, str2);
    cout << str3 << endl;
    cout << "strcmp:" << strcmp(str3, str1) << endl;
    cout << "strchr:" << strchr(str3, 'g') << endl;
    cout << "strstr:" << strstr(str3, "og") << endl;
    cout << "len3:" << strlen(str3) << endl;
    return 0;
}
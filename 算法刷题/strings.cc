/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-01-13 16:06:00
 * LastEditTime: 2020-01-13 16:20:00
 * Description: 文件描述信息
 */
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char str[11];
    strcpy(str, "0123456789"); // 字符串拷贝
    char str1[] = "hello world";
    char str2[] = "hello world";
    char* str3 = "hello world";
    char* str4 = "hello world";
    char* str5 = "hello world";
    char* str6 = "hello world";
    printf("Str1: %d\n",  str1);
    printf("Str2: %d\n",  str2);
    printf("Str3: %d\n",  str3);
    printf("Str4: %d\n",  str4);
    printf("Str5: %d\n",  str5);
    printf("Str6: %d\n",  str6);
    cout << "string addr " << endl;
    
    return 0;
}
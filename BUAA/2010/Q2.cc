#include <cstdio>
#include <iostream>

using namespace std;

// 注意程序书写正确性。有时候思路正确，但是代码书写错误；

int main(){
    freopen("Q2.in", "r", stdin); // 重定向到标准输入；
    char str1[100];
    char str2[100];
    char str3[200];
    while(scanf("%s", str1)!=EOF){
        scanf("%s", str2);
        int size1 = strlen(str1); // 获取第一个字符串的长度
        int size2 = strlen(str2); // 获取第二个字符串的长度
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < size1 && j < size2){
            if (str1[i] > str2[j])
            {
                str3[k] = str2[j];
                k++;
                j++;
            }
            if (str1[i] < str2[j])
            {
                str3[k] = str1[i];
                k++;
                i++;
            }
            if (str1[i] == str2[j])
            {
                str3[k] = str1[i];
                k++;
                i++;
                j++;
            }
        }
        
        while (i < size1)
        {
            str3[k] = str1[i];
            k++;
            i++;
        }
        
        while (j < size2)
        {
            str3[k] = str2[j];
            k++;
            j++;
        }
        str3[k] = '\0';
        cout << str3 << endl;
    }
    return 0;
}
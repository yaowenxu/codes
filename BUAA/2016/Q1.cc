#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

// 逆序数处理，进行数位反转；然后进行判断是否进行输出；
int main(){
    freopen("Q1.in", "r", stdin); // 进行重定向输入到文件；
    int n = 0;
    vector<char> vec; // 进行存储每一位；
    while (scanf("%d", &n)!=EOF)
    {
        int m = 0;
        int save_n = n;
        
        while(n % 10 != 0 || n / 10 != 0){
            m *= 10;
            vec.push_back(n%10+'0'); // 进行保存；
            m += n % 10;
            n = n / 10; // 进行缩放n的范围。
        }
        vec.push_back('\0');
        n = save_n;
        if (m % n == 0)
        {
            cout << n <<  "*" << m/n << "=" << m << endl;
        }else{
            cout << n << " " << vec.data() << endl; // 进行输出字符串；
        }
        vec.clear(); // 进行清空内存；
    }
    return 0;
}
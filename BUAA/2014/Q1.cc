// 阶乘数
// 编译命令：c++ -std=c++11 Q1.cc -o out ; ./out ; rm out
#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;
void solve(int num);

int main(){
    freopen("Q1_input.txt", "r", stdin); // 重定向到标准输入；
    int number;
    while(scanf("%d", &number)!=EOF){
        solve(number);
    }
    return 0;
}

void solve(int num){
    cout << num << ",";
}
//编译命令： c++ Q1.cc -std=c++11 -o out; ./out ; rm out
#include <cstdio>
#include <iostream>
#include <deque>
using namespace std;

bool is_prime[100001] = {0}; // 提前打表；// 初始化为false;

// 素数筛；进行打表优化；
void shaizi(int n){
    is_prime[0] = false;
    is_prime[1] = true;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] == true)
        {
            for (int j = 2*i; j < n; j+=i)
            {
                is_prime[j] = false;
            }
        }
    }
}

int main(){
    freopen("Q1.in", "r", stdin); // 重定向文件到输入；
    int a, b;
    memset(is_prime, 1, 100001*sizeof(bool)); // 进行初始化为 true;
    while (scanf("%d %d", &a, &b)!=EOF)
    {
        shaizi(b);
        deque<int> numdq;
        int olddef = -1;
        bool out = false;
        for (int i = a; i <= b; i++)
        {
            if (is_prime[i])
            {
                numdq.push_back(i);
            }
            if (numdq.size()==3)
            {
                int index = 0;
                int arr[3];
                for (auto it = numdq.begin(); it < numdq.end(); it++)
                {
                    arr[index] = *it;
                    index++;
                }
                int def = -1;
                if((arr[2]-arr[1]) == (arr[1]-arr[0])){
                    def = arr[2] - arr[1];
                    out = true;
                    if (def != olddef){
                        for (int k = 0; k < 3; k++)
                        {
                            cout << arr[k] << " ";
                        }
                    }else{
                        cout << arr[2] << " ";
                    }
                    olddef = def;
                }else{
                    if (out)
                    {
                        cout << endl;
                    }
                    out = false;
                    olddef = -1;
                }
                numdq.pop_front();
            }
        }
    }

    return 0;
}
// 旋转矩阵；
// 编译命令：c++ -std=c++11 Q2.cc -o out ; ./out ; rm out
#include <cstdio>
#include <iostream>
using namespace std;

bool judge(int A[9][9], int B[9][9], int Ai, int Aj, int Bi, int Bj){
    // 旋转0度；或者 旋转180度；
    if (Ai == Bi && Aj == Bj) 
    {
        // 判断旋转0度；
        int flag0 = true;
        for (int i = 0; i < Ai; i++)
        {
            for (int j = 0; j < Aj; j++)
            {
                if (A[i][j] != B[i][j])
                {
                    flag0 = false;
                }
            }
        }
        if (flag0)
        {
            cout << "0" << endl;
            return true;
        }
        
        // 判断旋转180度；
        int flag1 = true;
        for (int i = 0; i < Ai; i++)
        {
            for (int j = 0; j < Aj; j++)
            {
                if (A[i][j] != B[Ai-i-1][Aj-j-1])
                {
                    flag1 = false;
                }
            }
        }
        if (flag1)
        {
            cout << "180" << endl;
            return true;
        }
    }
    
    // 旋转90度；或者 旋转270度；
    if (Ai == Bj && Aj == Bi)
    {
        // 判断旋转90度；
        int flag0 = true;
        for (int i = 0; i < Ai; i++)
        {
            for (int j = 0; j < Aj; j++)
            {
                if (A[i][j] != B[j][Ai-i-1])
                {
                    flag0 = false;
                }
            }
        }
        if (flag0)
        {
            cout << "90" << endl;
            return true;
        }
        
        // 判断旋转270度；
        int flag1 = true;
        for (int i = 0; i < Ai; i++)
        {
            for (int j = 0; j < Aj; j++)
            {
                if (A[i][j] != B[Aj-j-1][i])
                {
                    flag1 = false;
                }
            }
        }
        if (flag1)
        {
            cout << "270" << endl;
            return true;
        }
    }
    return false;
}

int main(){
    freopen("Q2.in", "r", stdin);
    int Ai, Aj;
    int Bi, Bj;
    int A[9][9];
    int B[9][9];
    while (scanf("%d %d", &Ai, &Aj)!=EOF)
    {
        for (int i = 0; i < Ai; i++)
        {
            for (int j = 0; j < Aj; j++)
            {
                scanf("%d", &A[i][j]); // 进行输入；
            } 
        }
        scanf("%d %d", &Bi, &Bj); // 进行输入第二个矩阵
        for (int i = 0; i < Bi; i++)
        {
            for (int j = 0; j < Bj; j++)
            {
                scanf("%d", &B[i][j]); // 进行输入；
            }
        }

        if (!judge(A, B, Ai, Aj, Bi, Bj)) // 进行判断两个矩阵是否相等；
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
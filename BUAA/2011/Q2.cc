// 矩阵替换；
#include <cstdio>
#include <iostream>
using namespace std;

void output(int A[20][20], int Ai, int Aj){
    for (int i = 0; i < Ai; i++)
    {
        for (int j = 0; j < Aj; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl; // 输出换行符；
    }
}

int main(){
    freopen("Q2.in", "r", stdin); // 进行重定向输入输出；
    int A[20][20]; // 表示A矩阵； 
    int B[20][20]; // 表示B矩阵；
    int Ai, Aj;
    int Bi, Bj;
    while(scanf("%d %d", &Ai, &Aj)!=EOF){
        for (int i = 0; i < Ai; i++)
        {
            for (int j = 0; j < Aj; j++)
            {
                scanf("%d", &A[i][j]); // 进行读入整数；
            }
        }
        scanf("%d %d", &Bi, &Bj);
        for (int i = 0; i < Bi; i++)
        {
            for (int j = 0; j < Bj; j++)
            {
                scanf("%d", &B[i][j]); // 进行读入整数；
            }
        }
        int indexi, indexj; // 替换的初始坐标；
        scanf("%d %d", &indexi, &indexj);
        indexi --; 
        indexj --;

        cout << indexi << endl;
        cout << indexj << endl;
        
        // 判断是否超出范围；
        if (!(indexi >=0 && indexi < Ai && indexj >=0 && indexj < Aj))
        {
            output(A, Ai, Aj);
        }else{
            for (int i = 0; i < Ai; i++)
            {
                bool first = false;
                for (int j = 0; j < Aj; j++)
                {

                    if (first)
                    {
                        cout << " "; // 进行输出空格，进行排版；
                    }else{
                        first = true;
                    }
                    // 进行输出替换后的矩阵；
                    if(i >= indexi && j >= indexj && i - indexi < Bi && j-indexj < Bj){
                        cout << B[i-indexi][j-indexj];
                    }else{
                        cout << A[i][j];
                    }
                }
                cout << endl; // 输出换行；
            }
        }
        
    }
    return 0;
}
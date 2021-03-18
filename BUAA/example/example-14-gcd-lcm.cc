#include <cstdio>
#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(a%b == 0){
        return b;
    }
    return gcd(b, a%b);
}

int lcm(int a, int b){
    return a/gcd(a, b)*b; // 按照此种顺序求解，可以防止溢出;
}

int main(){
    cout << gcd(10, 2) << endl;
    cout << lcm(10, 3) << endl;
    return 0;
}
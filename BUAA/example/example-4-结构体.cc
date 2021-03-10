// 编译操作：c++ -std=c++11 example-4-结构体.cc -o out ; ./out; rm out
// C语言字符串接口配置；

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

struct Books
{
    char title[50];
    char author[50];
};


int main(){
    
    struct Books book;
    strcpy(book.title, "yaowen");
    strcpy(book.author, "xu ");
    
    cout << "book: " << book.author << book.title << endl;

    return 0;
}
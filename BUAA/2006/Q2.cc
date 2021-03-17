#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct STU{
    char name[200];
    int grade;
};

bool CMP(const STU &a, const STU &b){
    if(a.grade == b.grade){
        // 如果分数相同，则按照名字的字典序进行排序。
        return strcmp(a.name, b.name) > 0; 
    }else{
        return a.grade > b.grade;
    }
}

int main(){
    freopen("Q2.in", "r", stdin); // 进行重定向输入到文件；
    char name[200];
    int gd;
    vector<STU> vec;
    while (scanf("%s %d", name, &gd)!=EOF)
    {
        STU stu;
        strcpy(stu.name, name);
        stu.grade = gd;
        vec.push_back(stu); // 进行添加入队列；
    }
    sort(vec.begin(), vec.end(), CMP); // 进行排序
    // 进行输出结果；
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cout << it->name << " : " << it->grade << endl;
    }
    return 0;
}
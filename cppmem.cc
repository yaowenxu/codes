/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-02-21 17:27:51
 * LastEditTime: 2020-02-21 17:36:37
 * Description: 文件描述信息
 */

#include <iostream>
using namespace std;
class Babe
{
public:
    Babe()
    {
        cout << "Create a Babe to talk with me" << endl;
    }
    ~Babe()
    {
        cout << "Babe don't go away,listen to me" << endl;
    }
};
int main()
{
    Babe* pbabe = new Babe[3];
    // delete pbabe;
    // delete pbabe;
    // pbabe = new Babe[3];
    delete []pbabe;
    return 0;
}
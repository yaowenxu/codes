/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-02-24 16:31:57
 * LastEditTime: 2020-02-24 16:34:13
 * Description: 文件描述信息
 */

#include <iostream>
using namespace std;
int main()
{
    double m ,n;
    m = 1;
    n = 0;
    try {
        cout << "before dividing." << endl;
        if( n == 0)
            throw -1.01; //抛出int类型异常
        else
            cout << m / n << endl;
        cout << "after dividing." << endl;
    }
    catch(double d) {
        cout << "catch(double) " << d <<  endl;
    }
    catch(int e) {
        cout << "catch(int) " << e << endl;
    }
    cout << "finished" << endl;
    return 0;
}

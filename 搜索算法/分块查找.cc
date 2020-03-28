/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-03-28 14:38:04
 * LastEditTime: 2020-03-28 16:21:35
 * Description: 分块查找，分为顺序表和索引表；
 * 测试数据：直接在代码中进行测试；
 */

#include <iostream>
using namespace std;

int seqtable[20] = {8, 14, 6, 9, 10, 22, 34, 18, 19, 31, 40, 38, 54, 66, 46, 71, 78, 68, 80, 85}; // 顺序表
int indextable[4][2] = {{14, 0},{34, 5},{66, 10},{85, 15}}; // 索引表 

void blocksearch1(int v = 85){
    // 二分查找；
    int start = 0;
    int stop = 3;
    // 顺序搜索的范围，该变量由二分搜索查表确定
    int s = 0;
    int e = 20;
    do{
        int mid =  (start+stop)/2;
        cout << "二分查找前：" << "start:" << start << " mid:" << mid << " stop:" << stop << " s=" << s << " e=" << e << endl;
        if(indextable[mid][0] < v){
            start = mid+1;
            if (mid == 3){
                cout << "无满足数据！" << endl;
                return;
            }
            s =  indextable[mid+1][1];
        }
        if(indextable[mid][0] >= v){
            stop = mid-1;
            if (mid < 3){
                e =  indextable[mid+1][1];
            }
        }
        cout << "二分查找后：" << "start:" << start << " mid:" << mid << " stop:" << stop << " s=" << s << " e=" << e << endl;
    }while(stop >= start);
    
    // 顺序搜索
    cout << "顺序搜索区间: " << "s=" << s << " e=" << e << endl; 
    int flag = true;
    for (int i = s; i < e; i++){
        if(seqtable[i] ==  v){
            cout << "满足索引：" << i << endl;
            flag = false;
            break;
        }
    }
    if (flag){
        cout << "无满足数据！" << endl;
    }
}

void blocksearch2(int v = 85){
    // 二分查找；
    int start = 0;
    int stop = 3;
    // 顺序搜索的范围，该变量由二分搜索查表确定
    int s = 0;
    int e = 20;
    do{
        int mid =  (start+stop)/2;
        cout << "二分查找前：" << "start:" << start << " mid:" << mid << " stop:" << stop << " s=" << s << " e=" << e << endl;
        if(indextable[mid][0] == v){  // 加入此判断，可以过早终止；
            s = indextable[mid][1];
            if (mid < 3){
                e =  indextable[mid+1][1];
            }
            break;
        }
        if(indextable[mid][0] < v){   // 加入此判断可以过早终止；
            start = mid+1;
            if (mid == 3){
                cout << "无满足数据！" << endl;
                return;
            }
            s =  indextable[mid+1][1];
        }
        if(indextable[mid][0] > v){
            stop = mid-1;
            if (mid < 3){
                e =  indextable[mid+1][1];
            }
        }
        cout << "二分查找后：" << "start:" << start << " mid:" << mid << " stop:" << stop << " s=" << s << " e=" << e << endl;
    }while(stop >= start);
    
    // 顺序搜索
    cout << "顺序搜索区间: " << "s=" << s << " e=" << e << endl; 
    int flag = true;
    for (int i = s; i < e; i++){
        if(seqtable[i] ==  v){
            cout << "满足索引：" << i << endl;
            flag = false;
            break;
        }
    }
    if (flag){
        cout << "无满足数据！" << endl;
    }
}

int main(){
    cout << "分块查找1:" << endl;
    blocksearch1();
    cout << endl;
    cout << "分块查找2:" << endl;
    blocksearch2();
}
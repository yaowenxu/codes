// 迭代器 iterator 
// 编译命令：c++ -std=c++11 example-6-iterator.cc -o out ; ./out ; rm out
// 迭代器是一种检查容器内元素并遍历元素的数据类型。
// 迭代器分为，输入迭代器，输出迭代器，前向迭代器，双向迭代器，随机存取迭代器。

#include <cstdio>
#include <vector>
#include <iostream>
#include <iterator>
#include <deque>
#include <list>
#include <map>
using namespace std;

int main(){
    
    // 我们可以将list，替换为deque和vector。其使用方法相同。
    list<int> vec;
    for (int i = 0; i < 6; i++)
    {
        vec.push_back(i); // 将数字加入到vector之中。
    }
    
    cout << vec.size() << endl;
    list<int>::iterator it;
    for ( it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // map迭代器测试；
    typedef map<int, char> MyMap; // 进行重新命名对象；
	map<int, char> mapTemp;
	for (int i = 0; i<6; i++)
	{
		mapTemp[i] = ('F'-i);
	}

	// 展示map的内容；
	cout <<"map: " <<endl;
	map<int, char>::iterator mit;
	for (mit = mapTemp.begin(); mit != mapTemp.end(); mit++)
	{
		cout << (*mit).first << " --> ";
		cout << (*mit).second << std::endl;
	}

    return 0;
}
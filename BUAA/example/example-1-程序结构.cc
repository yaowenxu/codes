// 编程模板；包含输入输出重定向功能；
// 编译命令：c++ -std=c++11 example.cc -o out ; ./out; rm out

// C++ STL 标准模板库
// Standard Template Library; 包含了诸多常用的基本数据结构和基本算法；

// 容器，用于管理某类对象的集合：STL 准备了七种基本的容器类型；
// 迭代器：用来在一个对象集合上进行遍历操作，每一种容器都提供了自己的迭代器；
// 算法：用来处理对象集合中的元素。sort, search, copy, erase;


// 序列式容器：向量vector, 双端队列 deque, 双向列表list;
// 关联式容器：set, multiset, map, multimap;
// 容器配接器：stack, queue, priority_queue;
// 容器共性：默认构造函数，复制构造函数，析构函数。empty, swap;
// begin(); 返回容器第一个元素的迭代器指针；
// end(); 返回容器最后一个元素后面一位的迭代器指针。
// rbegin(); 返回一个逆向迭代器指针，指向容器最后一个元素。
// rend(); 返回一个逆向迭代器指针，指向容器首个元素前面一位。

// vector：空间连续，可顺序访问，扩增时存在内存拷贝；适用于频繁随机访问的场景。
// deque：空间不连续，通过指针数组组成空间连续的假象。是list与vector折中；适用于频繁随机访问，又关心两端插入的场景。
// list：空间不连续，分配于堆上；不支持随机访问，但插入和删除效率高。
// set：红黑树实现，每次插入的时候，都调整红黑树。set中元素不重复，并且元素自动排序。
// multiset：允许包含多个相同的值。
// map：由红黑树实现，其元素都是键值/实值，所形成的一个对组；由红黑树实现。适用于key/value的场景。
// multimap：允许包含多个相同的键值。
// stack：对元素采取后进先出的管理策略。
// queue：对元素采取先进先出的管理策略，可认为是一个普通的缓冲区。
// priority_queue：容器中的元素可以拥有不同的优先权。其效果相当于一个buffer，下一个元素是优先级最高的元素。当多个元素有相同优先级时，具体次序无明确定义。

// 参考：https://www.cnblogs.com/linuxAndMcu/p/10254542.html

#include <cstdio>
#include <iostream>

int main(){
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout); // 使用w模式，每次打开文件都清空内容；
    std::string buffer;
    while (std::cin >> buffer)
    {
        std::cout << buffer << " ";
    }
    std::cout << std::endl;
    return 0;
}
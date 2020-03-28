/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-03-28 17:14:40
 * LastEditTime: 2020-03-28 18:56:58
 * Description: 实现链表结构
 */

#include <iostream>
using namespace std;

struct node // 此节点，可以构建双向链表
{
    int val;
    struct node* next; // 下一个
    struct node* prev; // 前一个
    node(){
        val = 0;
        next = nullptr;
        prev = nullptr;
    }
};

// 单链表实现
struct LinkedList
{
    int size; // 当前链表中的个数
    struct node* head; 
    struct node* tail; 
    LinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    ~LinkedList(){
        struct node* p;
        while(head != nullptr){
            p = head;
            head = head->next;
            free(p);
        }
        cout << "链表析构" << endl;
    }
    void push_back(int v){
        struct node* p = (struct node*)malloc(sizeof(struct node)); // 此处使用的是堆上内存；
        p->val = v;
        if(tail == nullptr){
            tail = p;
            head = p;
        }else{
            
            tail->next = p;
            tail = p;
        }
        size++;
    }
    int getsize(){
        return size;
    }
    void printlist(){
        struct node* p;
        p = head;
        for(int i = 0; i < size; i++){
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main(){
    LinkedList l;
    l.push_back(1);
    cout << l.getsize()<< endl;
    l.printlist();
    l.push_back(2);
    l.push_back(3);
    cout << l.getsize()<< endl;
    l.printlist();
    return 0;
}
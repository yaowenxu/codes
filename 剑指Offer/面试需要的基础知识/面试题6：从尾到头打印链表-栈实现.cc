/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-04-02 22:55:40
 * LastEditTime: 2020-04-02 23:25:54
 * Description: 从尾到头打印链表；
 */
#include <vector>
#include <stack>
using namespace std;

// 链表节点的数据结构；
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };
 
 // 使用递归， 来进行解决链表逆序问题；
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        ListNode* p;
        p = head;
        if (p == nullptr)
        {
            return res;
        }
        res = reversePrint(p->next);
        res.push_back(p->val);
        return res;
    }
};
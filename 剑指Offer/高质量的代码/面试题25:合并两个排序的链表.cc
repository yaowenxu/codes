#include <iostream>
// 合并两个链表，要考虑一方链表为空的情况或者双方链表为空的情况；
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* pnew = nullptr;
        ListNode* phead = nullptr;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                if (phead==nullptr)
                {
                    phead = l1; // 获取头
                    pnew = l1;
                }else{
                    pnew->next = l1;
                    pnew = l1;
                }
                l1 = l1->next;
            }else{
                if (phead==nullptr)
                {
                    phead = l2; // 获取头；
                    pnew = l2;
                }else{
                    pnew->next = l2;
                    pnew = l2;
                }
                l2 = l2->next;
            }
        }
        if (l1!=nullptr)
        {
            if (pnew == nullptr)
            {
                return l1;
            }
            pnew->next = l1;
        }
        if (l2!=nullptr)
        {
            if (pnew == nullptr)
            {
                return l2;
            }
            pnew->next = l2;
        }
        return phead;
    }
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
// 进行实现反转链表操作；
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
        {
            return head;
        }
        ListNode* pnew = nullptr;
        ListNode* phead = nullptr;
        phead = head->next;
        pnew =  head;
        pnew->next = nullptr;
        while (phead!=nullptr)
        {
            ListNode* tmp = phead;
            phead = phead->next;
            tmp->next = pnew;
            pnew = tmp;
        }
        return pnew;
    }
};
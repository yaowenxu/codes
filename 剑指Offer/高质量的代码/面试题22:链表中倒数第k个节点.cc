
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *phead;
        ListNode *p;
        p = head; phead = head;
        while (k--)
        {
            if (p==nullptr)
            {
                return head;
            }
            p = p->next;
        }
        while (p!=nullptr)
        {
            p=p->next;
            phead = phead->next;
        }
        return phead;
    }
};
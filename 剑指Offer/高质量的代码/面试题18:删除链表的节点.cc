
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == nullptr) // 考虑边界值 head == nullptr 的情况；
        {
            return head;
        }
        if(head->val == val){ // 考虑边界值 第一个就是要删的节点的 情况；
            head = head->next;
        }
        ListNode* p = head;
        while (p->next != nullptr) // 考虑边界值 判断是否到达最后一个节点；
        {
            if (p->next->val == val)
            {
                p->next = p->next->next;
                return head;
            }
            p = p->next; 
        }
        return head;
    }
};
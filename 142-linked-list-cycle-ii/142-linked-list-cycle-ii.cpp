/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head,*fast=head;
        bool ok=0;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                ok=1;
                break;
            }
        }
        if(!ok)
            return nullptr;
        fast=head;
        while(1)
        {
            if(slow==fast)
                return slow;
            slow=slow->next;
            fast=fast->next;
        }
    }
};
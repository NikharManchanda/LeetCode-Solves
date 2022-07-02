/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head,*fast=head;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        if(fast && !fast->next)
            slow=slow->next;
        ListNode* nxt=nullptr,*pre=nullptr;
        while(slow)
        {
            nxt=slow->next;
            slow->next=pre;
            pre=slow;
            slow=nxt;
        }
        while(pre)
        {
            if(pre->val!=head->val)
                return 0;
            pre=pre->next;
            head=head->next;
        }
        return 1;
    }
};
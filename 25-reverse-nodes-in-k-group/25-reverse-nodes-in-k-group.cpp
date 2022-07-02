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
    ListNode* reverse(ListNode* head,ListNode* end)
    {
        ListNode* pre=nullptr,*nxt=nullptr;
        while(head!=end)
        {
            nxt=head->next;
            head->next=pre;
            pre=head;
            head=nxt;
        }
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur=head;
        for(int i=1;i<=k;i++)
        {
            if(!cur)
                return head;
            cur=cur->next;
        }
        ListNode* tmp=reverse(head,cur);
        head->next=reverseKGroup(cur,k);
        return tmp;
    }
};
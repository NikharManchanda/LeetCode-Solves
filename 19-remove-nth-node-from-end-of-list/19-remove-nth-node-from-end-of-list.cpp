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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur=head;
        int len=0;
        while(cur)
        {
            cur=cur->next;
            len++;
        }
        if(len==n)
            return head->next;
        cur=head;
        ListNode* tmp=nullptr;
        for(int i=1;i<=len-n-1;i++)
        {
            cur=cur->next;
        }
        if(cur->next)
            cur->next=cur->next->next;
        return head;
    }
};
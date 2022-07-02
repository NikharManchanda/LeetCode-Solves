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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)
            return head;
        if(head->next==nullptr)
            return head;
        ListNode* tmp=head->next;
        ListNode* nxt=reverseList(head->next);
        tmp->next=head;
        head->next=nullptr;
        return nxt;
    }
};
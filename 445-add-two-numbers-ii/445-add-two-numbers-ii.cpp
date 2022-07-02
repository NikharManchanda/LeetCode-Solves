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
    ListNode* reverse(ListNode* head) {
        if(head==nullptr)
            return head;
        if(head->next==nullptr)
            return head;
        ListNode* nxt=reverse(head->next);
        head->next->next=head;
        head->next=nullptr;
        return nxt;
    }
    ListNode* addTwoNumber(ListNode* l1, ListNode* l2) {
        ListNode* root=new ListNode(),*head=root;
        int carry=0;
        while(l1 || l2 || carry)
        {
            int val1=0,val2=0;
            if(l1)
                val1=l1->val;
            if(l2)
                val2=l2->val;
            ListNode* node=new ListNode(val1+val2+carry);
            carry=node->val/10;
            node->val=node->val%10;
            head->next=node;
            head=head->next;
            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;
        }
        return root->next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        ListNode* head=addTwoNumber(l1,l2);
        head=reverse(head);
        return head;
    }
};
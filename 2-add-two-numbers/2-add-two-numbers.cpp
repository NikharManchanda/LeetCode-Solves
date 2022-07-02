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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
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
};
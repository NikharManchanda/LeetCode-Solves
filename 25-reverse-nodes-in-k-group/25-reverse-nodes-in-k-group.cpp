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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * dummy,*first,*second,*temp,*tempnxt;
        first=second=temp=tempnxt=nullptr,dummy=new ListNode(-1);
        dummy->next=head,temp=head;
        int count=0;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        temp=dummy;
        for(int times=1;times<=count/k;times++)
        {
            tempnxt=temp->next;
            first=temp->next;
            ListNode* pre=temp;
            for(int i=1;i<=k;i++)
            {
                second=first->next;
                first->next=pre;
                pre=first;
                first=second;
            }
            temp->next=pre;
            tempnxt->next=second;
            temp=tempnxt;
        }
        return dummy->next;
    }
};
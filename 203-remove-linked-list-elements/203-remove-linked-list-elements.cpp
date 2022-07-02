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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* node=head;
        while(node && node->val==val)
        {
            ListNode* tmp=node;
            node=node->next;
            delete(tmp);
        }
        head=node;
        while(node)
        {
            while(node->next && node->next->val==val)
            {
                ListNode* tmp=node->next;
                node->next=tmp->next;
                delete(tmp);
            }
            node=node->next;
        }
        return head;
    }
};
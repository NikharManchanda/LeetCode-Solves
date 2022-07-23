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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* A) {
        if(!A)
            return nullptr;
        ListNode* slow=A,*fast=A,*prev=nullptr;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        TreeNode* head=new TreeNode(slow->val);
        if(prev)
        {
            prev->next=nullptr;
            head->left=sortedListToBST(A);
        }
        if(slow->next)
            head->right=sortedListToBST(slow->next);
        return head;
    }
};
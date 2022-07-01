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
    TreeNode* pre=nullptr;
    void flatten(TreeNode* root) {
        
        // Method 1 Right,Left,Root, using prev
        // TC O(n) && SC O(n)
        if(root==nullptr)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right=pre;
        root->left=nullptr;
        pre=root;
        
        // Method 2 Modified Morris
        // TreeNode* cur=root;
        // while(cur)
        // {
        //     if(cur->left)
        //     {
        //         TreeNode* prev=cur->left;
        //         while(prev->right)
        //         {
        //             prev=prev->right;
        //         }
        //         prev->right=cur->right;
        //         cur->right=cur->left;
        //         cur->left=nullptr;
        //     }
        //     cur=cur->right;
        // }
        // return ;
        
        TreeNode* cur=root;
        while(cur)
        {
            if(cur->left)
            {
                TreeNode* tmp=cur->left;
                while(tmp->right)
                {
                    tmp=tmp->right;
                }
                tmp->right=cur->right;
                cur->right=cur->left;
                cur->left=nullptr;
            }
            cur=cur->right;
        }
        
    }
};
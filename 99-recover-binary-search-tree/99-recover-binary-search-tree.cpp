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
// 2 3 4 5 6 7
// 6 3 4 5 2 7

// 1 2 3 4 
// 1 3 2 4
class Solution {
public:
    TreeNode* prevNode=nullptr,*first=nullptr,*second=nullptr;
    void inorder(TreeNode* root){
        if(!root)
            return;
        inorder(root->left);
        if(!first && prevNode && root->val<prevNode->val)
            first=prevNode;
        if(first!=nullptr && root->val<prevNode->val)
            second=root;
        prevNode=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root); 
        swap(first->val,second->val);
    }
};
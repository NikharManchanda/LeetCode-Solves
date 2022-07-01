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
    // Method 1 Recursion
    // int c=0,k,ans=-1;
    // void fun(TreeNode* root)
    // {
    //     if(!root)
    //         return ;
    //     fun(root->left);
    //     c++;
    //     if(c==k)
    //     {
    //         ans=root->val;
    //         return ;
    //     }
    //     fun(root->right);
    // }
    int kthSmallest(TreeNode* root, int K) {
        // Method 1 Inorder trav is sorted , kth element of inorder 
        // TC : O(N) , SC: O(N) stack space for recursion  
        
        // Start of Method 1
        // k=K;
        // fun(root);
        // return ans;
        
        // Method 2
        // Iterative Inorder 
        
        stack<TreeNode*> st;
        while(1)
        {   
            while(root)
            {
                st.push(root);
                root=root->left;     
            }
            root=st.top();
            st.pop();
            K--;
            if(K==0)
            {
                return root->val;
            }
            root=root->right;
        }
        return -1;
        
        // Method 3
        // Space optimized 
        // Morris traversal using threaded binary search tree 
        // TC : Amortized O(N) , SC: O(1)
        // Note: dlt the threads before returning checker
        // of judges else rte is thrown by judges
        // Start of method 2
        // int c=0,ans=-1;
        // while(root)
        // {
        //     if(root->left==nullptr)
        //     {
        //         c++;
        //         if(c==K)
        //             ans=root->val;
        //         root=root->right;
        //     }
        //     else
        //     {
        //         TreeNode* cur=root->left;
        //         while(cur->right && cur->right!=root)
        //         {
        //             cur=cur->right;
        //         }
        //         if(cur->right==nullptr)
        //         {
        //             cur->right=root;
        //             root=root->left;
        //         }
        //         else
        //         {
        //             cur->right=nullptr;
        //             c++;
        //             if(c==K)
        //               ans=root->val;
        //             root=root->right;
        //         }
        //     }
        // }
        // return ans;
    }
};
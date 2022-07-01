class Solution {
public:
    TreeNode* tar;
    queue<TreeNode*> q;
    int vis[505];
    unordered_map<TreeNode*,TreeNode*> par;
    void fun(TreeNode* root,TreeNode* p)
    {
        if(!root)
            return;
        if(root==tar)
        {
            q.push(root);
            vis[root->val]=1;
        }
        if(p)
            par[root]=p;
        fun(root->right,root);
        fun(root->left,root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        tar=target;
        fun(root,nullptr);
        vector<int> ans;
        while(!q.empty())
        {
            auto top=q.front();
            q.pop();
            if(vis[top->val]==k+1)
            {
                ans.push_back(top->val);
            }
            if(vis[top->val]>k+1)
                break;
            if(par.find(top)!=par.end() && !vis[par[top]->val])
            {
                q.push(par[top]);
                vis[par[top]->val]=1+vis[top->val];
            }
            if(top->right && !vis[top->right->val])
            {
                q.push(top->right);
                vis[top->right->val]=1+vis[top->val];
            }
            if(top->left && !vis[top->left->val])
            {
                q.push(top->left);
                vis[top->left->val]=1+vis[top->val];
            }
        }
        return ans;
    }
};
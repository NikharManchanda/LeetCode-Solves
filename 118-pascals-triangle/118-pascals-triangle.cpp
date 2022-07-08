class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i].push_back(1);
            for(int j=1;j<=i;j++)
            {
                if(j!=i)
                    ans[i].push_back(ans[i-1][j]+ans[i-1][j-1]);
                else
                    ans[i].push_back(ans[i-1][j-1]);
            }
        }
        return ans;
    }
};
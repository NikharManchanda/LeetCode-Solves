class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(m,vector<int>(n,1));
        vector<int> dp(n,1);
        for(int i=1;i<m;i++)
        {
            vector<int> cur(n,1);
            for(int j=1;j<n;j++)
            {
                cur[j]=dp[j]+cur[j-1];
            }
            dp=cur;
        }
        return dp[n-1];
    }
};
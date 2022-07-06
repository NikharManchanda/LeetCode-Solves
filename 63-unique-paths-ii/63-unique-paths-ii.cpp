class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        dp[1][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(!a[i-1][j-1])
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[n][m];
    }

};
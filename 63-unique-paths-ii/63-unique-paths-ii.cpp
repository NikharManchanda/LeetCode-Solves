class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1)
                {
                    dp[i][j]=0;
                    continue;
                }
                if(i==0 && j==0)
                {
                    dp[i][j]=1;
                    continue;
                }
                int top=0,left=0;
                if(i>=1)
                    top=dp[i-1][j];
                if(j>=1)
                    left=dp[i][j-1];
                dp[i][j]=top+left;
            }
        }
        return dp[n-1][m-1];
    }
};
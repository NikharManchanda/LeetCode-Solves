class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<int>dp(m+1);
        dp[1]=!a[0][0];
        for(int i=1;i<=n;i++)
        {
            vector<int>cur(m+1);
            for(int j=1;j<=m;j++)
            {
                if(!a[i-1][j-1])
                    cur[j]=dp[j]+cur[j-1];
            }
            dp=cur;
        }
        return dp[m];
    }

};
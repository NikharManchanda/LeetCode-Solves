class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size(),ans=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                dp[i][j]=triangle[i][j];
                if(i>=1)
                {   
                    if(j>=1)
                        dp[i][j]+=min(dp[i-1][j-1],dp[i-1][j]);
                    else 
                        dp[i][j]+=dp[i-1][j];
                }
                if(i==n-1)
                    ans=min(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
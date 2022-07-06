class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size(),ans=INT_MAX;
        vector<int> dp(n,INT_MAX);
        for(int i=0;i<n;i++)
        {
            vector<int> cur(n,INT_MAX);
            for(int j=0;j<=i;j++)
            {
                cur[j]=triangle[i][j];
                if(i>=1)
                {   
                    if(j>=1)
                        cur[j]+=min(dp[j-1],dp[j]);
                    else 
                        cur[j]+=dp[j];
                }
                if(i==n-1)
                    ans=min(ans,cur[j]);
            }
            dp=cur;
        }
        return ans;
    }
    
};
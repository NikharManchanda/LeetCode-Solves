class Solution {
public:
    
    // Tabular Dp
    
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>>dp(m,vector<int>(n,1));
    //     for(int i=1;i<m;i++)
    //     {
    //         for(int j=1;j<n;j++)
    //         {
    //             dp[i][j]=dp[i-1][j]+dp[i][j-1];
    //         }
    //     }
    //     return dp[m-1][n-1];
    // }
    
    // Space optimised
    
    // int uniquePaths(int m, int n) {
    //     vector<int> dp(n,1);
    //     for(int i=1;i<m;i++)
    //     {
    //         vector<int> cur(n,1);
    //         for(int j=1;j<n;j++)
    //         {
    //             cur[j]=dp[j]+cur[j-1];
    //         }
    //         dp=cur;
    //     }
    //     return dp[n-1];
    // }
    
    // Further Optimsed
    
    // int uniquePaths(int m, int n) {
    //     vector<int> dp(n,1);
    //     for(int i=1;i<m;i++)
    //     {
    //         for(int j=1;j<n;j++)
    //         {
    //             dp[j]=dp[j]+dp[j-1];
    //         }
    //     }
    //     return dp[n-1];
    // }
    
    // Math based solution
    long long int nCr(int n, int r)
    {
        long long int ans=1;
        for(int i=1;i<=r;i++)
            ans=(ans*(n-r+i))/i;
        return ans;
    }
    int uniquePaths(int m, int n) {
        return nCr(m-1+n-1,m-1);
    }

    
};
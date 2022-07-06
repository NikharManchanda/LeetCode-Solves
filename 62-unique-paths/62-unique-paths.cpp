class Solution {
public:
    
    // Tabular Dp
//     int uniquePaths(int m, int n) {
//         vector<vector<int>>dp(m,vector<int>(n,1));
//         for(int i=1;i<m;i++)
//         {
//             for(int j=1;j<n;j++)
//             {
//                 dp[i][j]=dp[i-1][j]+dp[i][j-1];
//             }
//         }
//         return dp[m-1][n-1];
//     }
    
    // Space optimised
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for(int i=1;i<m;i++)
        {
            // vector<int> cur(n,1);
            for(int j=1;j<n;j++)
            {
                dp[j]=dp[j]+dp[j-1];
            }
            // dp=cur;
        }
        return dp[n-1];
    }
    
};
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='0')
                {
                    continue;
                }
                int x,y,z;
                x=(i>=1)?dp[i-1][j]:0;
                y=(j>=1)?dp[i][j-1]:0;
                z=(i>=1 && j>=1)?dp[i-1][j-1]:0;
                dp[i][j]=1+min({x,y,z});
                ans=max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};
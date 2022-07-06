class Solution {
private:
    int minPath(int i, int j, vector<vector<int>>&grid,vector<vector<int>>&dp){     
        if(i==0 && j==0)
            return grid[0][0];
        if(i<0 || j<0)
            return 1e9;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=grid[i][j] + 
            min(minPath(i,j-1,grid,dp),minPath(i-1,j,grid,dp));
    } 
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return minPath(n-1,m-1,grid,dp);
    }
};
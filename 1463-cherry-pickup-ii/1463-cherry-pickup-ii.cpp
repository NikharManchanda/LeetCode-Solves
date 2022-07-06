class Solution {
private:
    int n,m;
    int helper(int row,int col1,int col2,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        
        if(row>=n || row<0 || col1>=m || col1<0 || col2<0 ||col2>=m)
            return 0;
        int sum=grid[row][col1];
        if(col1!=col2)
            sum+=grid[row][col2];
        if(row==n-1)
            return sum;
        if(dp[row][col1][col2]!=-1)
            return dp[row][col1][col2];
        int val=0;
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                val=max(val,helper(row+1,col1+i,col2+j,grid,dp));
            }
        }
        return dp[row][col1][col2]=sum+val;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return helper(0,0,m-1,grid,dp);
    }
};
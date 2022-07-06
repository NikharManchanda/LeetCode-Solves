class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=1;i<n;i++)
        {
            for(int j=n-1;j>=0;j--)
            {
                int val=grid[i-1][j];
                if(j>=1)
                    val=min(val,grid[i-1][j-1]);
                if(j+1<n)
                    val=min(val,grid[i-1][j+1]);
                grid[i][j]+=val;
            }
        }
        return *min_element(grid[n-1].begin(),grid[n-1].end());
    }
};
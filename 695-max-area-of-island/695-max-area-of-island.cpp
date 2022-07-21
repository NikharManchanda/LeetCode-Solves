class Solution {
public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    int n,m;
    int vis[55][55];
    int dfs(int i, int j,vector<vector<int>>&grid)
    {
        vis[i][j]=1;
        int c=1;
        for(int k=0;k<4;k++)
        {
            int nx=i+dx[k],ny=j+dy[k];
            if(nx<n && nx>=0 && ny>=0 & ny<m &&!vis[nx][ny] && grid[nx][ny]==1)
            {
                c+=dfs(nx,ny,grid);
            }
        }
        return c;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int cur=dfs(i,j,grid);
                    ans=max(ans,cur);                    
                }
            }
        }
        return ans;
    }
};
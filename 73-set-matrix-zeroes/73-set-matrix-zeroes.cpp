class Solution {
public:
    // Space O(n+n)
    
    // void setZeroes(vector<vector<int>>& grid) {
    //     int n=grid.size(),m=grid[0].size();
    //     vector<int> row(n),col(m);
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<m;j++)
    //         {
    //             if(!grid[i][j])
    //             {
    //                 row[i]=1;
    //                 col[j]=1;
    //             }
    //         }
    //     }
    //     for(int i=0;i<n;i++)
    //     {
    //         if(row[i])
    //         {
    //             for(int j=0;j<m;j++)
    //             {
    //                 grid[i][j]=0;
    //             }
    //         }
    //     }
    //     for(int i=0;i<m;i++)
    //     {
    //         if(col[i])
    //         {
    //             for(int j=0;j<n;j++)
    //             {
    //                 grid[j][i]=0;
    //             }
    //         }
    //     }
    //     return ;
    // }
    
    // Space O(n)
    void setZeroes(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int> col(m);
        for(int i=0;i<n;i++)
        {
            bool ok=0;
            for(int j=0;j<m;j++)
            {
                if(!grid[i][j])
                {
                    ok=1;
                    col[j]=1;
                }
            }
            if(ok)
                for(int j=0;j<m;j++)
                    grid[i][j]=0;
        }
        for(int i=0;i<m;i++)
        {
            if(col[i])
            {
                for(int j=0;j<n;j++)
                {
                    grid[j][i]=0;
                }
            }
        }
        return ;
    }
};
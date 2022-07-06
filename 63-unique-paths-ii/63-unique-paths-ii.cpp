class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        
        //Space O(n)
        // vector<int>dp(m+1);
        // dp[0]=!a[0][0];
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         if(!a[i][j])
        //         {
        //             if(j>=1)
        //                 dp[j]+=dp[j-1];
        //         }
        //         else
        //             dp[j]=0;
        //     }
        // }
        // return dp[m-1];
    
        //Space O(1)
        a[0][0]^=1;
        for(int i=1;i<n;i++)
            a[i][0]=a[i-1][0] && !a[i][0];
        
        for(int i=1;i<m;i++)
            a[0][i]=a[0][i-1] && !a[0][i];
        
        for(int i=1;i<n;i++)
            for(int j=1;j<m;j++)
                a[i][j]=(!a[i][j])?a[i-1][j]+a[i][j-1]:0;
        
        return a[n-1][m-1];
    }

};
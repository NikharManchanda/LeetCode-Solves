class Solution {
public:
    // Iterative/Tabulation  DP
    
    // int climbStairs(int n) {
    //     int ways[n+1];
    //     ways[0]=ways[1]=1;
    //     for(int i=2;i<=n;i++)
    //         ways[i]=ways[i-1]+ways[i-2];
    //     return ways[n];
    // }
    
    // Space optimised Iterative/Tabulation DP
    int climbStairs(int n) {
        int prev1,prev2;
        prev2=prev1=1;
        for(int i=2;i<=n;i++)
        {
            int cur=prev1+prev2;
            prev2=prev1;
            prev1=cur;
        }
        return prev1;
    }
};
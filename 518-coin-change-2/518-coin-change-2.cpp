class Solution {
public:
    
    // int change(int target, vector<int>& coins) {
    //     vector<int>dp(target+1,0);
    //     dp[0]=1;
    //     for(int i=0;i<coins.size();i++){
    //         for(int j=coins[i];j<=target;j++){
    //             dp[j]+=dp[j-coins[i]];
    //         }
    //     }
    //     return dp[target];
    // }
    
    int change(int target, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(target+1,0));
        for(int i=0;i<=target;i+=coins[0]){
            dp[0][i]=1;
        }
        for(int i=1;i<coins.size();i++){
            dp[i][0]=1;
            for(int j=1;j<=target;j++){
                dp[i][j]+=dp[i-1][j];
                if(j-coins[i]>=0)
                    dp[i][j]+=dp[i][j-coins[i]];
            }
        }
        return dp[coins.size()-1][target];
    }
};
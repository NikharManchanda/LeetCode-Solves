class Solution {
public:
    int change(int target, vector<int>& coins) {
        vector<int>dp(target+1,0);
        dp[0]=1;
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<=target;j++){
                dp[j]+=dp[j-coins[i]];
            }
        }
        return dp[target];
    }
};
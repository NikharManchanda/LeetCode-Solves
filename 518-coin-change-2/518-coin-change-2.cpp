class Solution {
public:
    int helper(int idx,vector<int>&coins,int sum,int target,vector<vector<int>>&dp){
        if(sum>target)
            return 0;
        if(sum==target)
            return 1;
        if(idx==coins.size())
            return 0;
        if(dp[idx][sum]!=-1)
            return dp[idx][sum];
        return dp[idx][sum]=helper(idx+1,coins,sum,target,dp)+
            helper(idx,coins,sum+coins[idx],target,dp);   
    }
    int change(int target, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(target+1,-1));
        return helper(0,coins,0,target,dp);
    }
};
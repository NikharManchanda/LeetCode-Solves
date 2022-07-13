class Solution {
public:
    int helper(int idx,int target,vector<int>&nums,vector<vector<int>>&dp,int S){
        
        if(idx==-1)
            return target==0;
        
        if(dp[idx][target+2000]!=-1)
            return dp[idx][target+2000];
        
        return dp[idx][target+2000]=helper(idx-1,target-nums[idx],nums,dp,S)
            +helper(idx-1,target+nums[idx],nums,dp,S);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int S=0;
        for(int i=0;i<nums.size();i++)
        { 
            S+=nums[i];
        }
        vector<vector<int>>dp(nums.size()+1,vector<int>(2*2000+1,-1));
        return helper(nums.size()-1,target,nums,dp,S);
    }
};
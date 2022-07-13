class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto x: nums)
            sum+=x;
        if(sum%2==1)
            return 0;
        vector<vector<int>>dp(nums.size(),vector<int>(sum/2+1,-1));
        return subsetSum(nums.size()-1,nums,sum/2,dp);
    }
    bool subsetSum(int idx,vector<int>&nums,int sum,vector<vector<int>>&dp){
        if(sum==0)
            return 1;
        if(idx==0)
            return nums[0]==sum;
        if(dp[idx][sum]!=-1)
            return dp[idx][sum];
        bool ok=subsetSum(idx-1,nums,sum,dp);
        if(sum>=nums[idx])
            ok=ok||subsetSum(idx-1,nums,sum-nums[idx],dp);
        return dp[idx][sum]= ok;
    }
};
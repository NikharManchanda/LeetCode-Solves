class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0];
        vector<int> dp(nums.size(),nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            dp[i]=max(nums[i],dp[i-1]+nums[i]);
            sum=max(sum,dp[i]);
        }
        return sum;
    }
};
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=2000,S=0;
        for(auto x: nums)
            S+=x;
        vector<vector<int>>dp(nums.size(),vector<int>(8000+1));
        dp[0][nums[0]+sum]=1;
        dp[0][-nums[0]+sum]+=1;
        for(int i=1;i<nums.size();i++){
            
            for(int j=-S;j<=S;j++)
            {
                dp[i][j+sum]=dp[i-1][j-nums[i]+sum];
                dp[i][j+sum]+=dp[i-1][j+nums[i]+sum];
            }
        }
        return dp[nums.size()-1][target+sum];
    }
};
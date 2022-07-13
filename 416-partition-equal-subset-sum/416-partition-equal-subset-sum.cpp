class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto x: nums)
            sum+=x;
        if(sum%2==1)
            return 0;
        return subsetSum(nums,sum/2);
    }
    bool subsetSum(vector<int>&nums,int sum){
        vector<vector<bool>>dp(nums.size(),vector<bool>(sum+1,0));
        for(int i=0;i<nums.size();i++){
            dp[i][0]=1;
        }
        if(nums[0]<=sum)
            dp[0][nums[0]]=1;
        for(int i=1;i<nums.size();i++){
            for(int j=1;j<=sum;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=nums[i])
                    dp[i][j]=dp[i][j]||dp[i-1][j-nums[i]];
            }
        }
        return dp[nums.size()-1][sum];
    }
};
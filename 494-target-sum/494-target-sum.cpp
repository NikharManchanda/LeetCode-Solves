class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto x: nums)
            sum+=x;
        if(target>sum || target<-sum)
            return 0;
        vector<vector<int>>dp(nums.size(),vector<int>(2*sum+1));
        dp[0][sum+nums[0]]=1;
        dp[0][sum-nums[0]]+=1;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<2*sum+1;j++){
                if(dp[i-1][j]!=0){
                    dp[i][j+nums[i]]+=dp[i-1][j];
                    dp[i][j-nums[i]]+=dp[i-1][j];
                }
            }
        }
        return dp[nums.size()-1][target+sum];
    }
};
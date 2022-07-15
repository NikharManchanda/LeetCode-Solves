class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<long long int> dp(target+2,0);
        dp[0]=1;
        for(int i=1;i<=target;i++)
        {
            int val=0;
            for(auto x: nums)
            {
                if(i-x>=0)
                {
                    val+=dp[i-x];
                }
            }
            dp[i]=val;
        }
        return dp[target];
    }
};
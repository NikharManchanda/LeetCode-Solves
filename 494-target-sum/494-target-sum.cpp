class Solution {
public:
    int helper(int idx,int target,vector<int>&nums){
        if(idx==-1)
        {       
            return (target==0);
        }
        return helper(idx-1,target-nums[idx],nums)
            +helper(idx-1,target+nums[idx],nums);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums.size()-1,target,nums);
    }
};
class Solution {
public:
    int helper(int idx,int target,vector<int>&nums,int x){
        if(idx==-1)
        {       
            if(target==0)return 1;
            return 0;
        }
        return helper(idx-1,target-nums[idx],nums,x)
            +helper(idx-1,target+nums[idx],nums,x);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums.size()-1,target,nums,target);
    }
};
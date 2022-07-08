class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0];
        int prev=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int cur=max(nums[i],prev+nums[i]);
            sum=max(sum,cur);
            prev=cur;
        }
        return sum;
    }
};
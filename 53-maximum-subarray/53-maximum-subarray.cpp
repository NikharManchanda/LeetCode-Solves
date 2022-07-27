class Solution {
public:
    // Space O(n) DP
    int maxSubArray(vector<int>& nums) {
      int max_sum=nums[0], sum=nums[0];
      int n=nums.size();
        for(int i=1; i<n; i++) {
            sum = max(nums[i], sum+nums[i]);
            if(sum>max_sum) {
                max_sum=sum;
            }
        }
        return max_sum;
    }
    
    // Space O(1) Dp , space optimisation 
    // int maxSubArray(vector<int>& nums) {
    //     int sum=nums[0];
    //     int prev=nums[0];
    //     for(int i=1;i<nums.size();i++)
    //     {
    //         int cur=max(nums[i],prev+nums[i]);
    //         sum=max(sum,cur);
    //         prev=cur;
    //     }
    //     return sum;
    // }
    
    
};
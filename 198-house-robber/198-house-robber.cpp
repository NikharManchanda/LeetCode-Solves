class Solution {
public:
    // Tabulation
    
    // int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     int max_money[n];
    //     max_money[0]=nums[0];
    //     for(int i=1;i<n;i++)
    //     {
    //         int val=max_money[i-1],val2=nums[i];
    //         if(i>=2)val2+=max_money[i-2];
    //         max_money[i]=max(val,val2);
    //     }
    //     return max_money[n-1];
    // }
    
    
    // Space Optimised
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev1=nums[0],prev2=0;
        for(int i=1;i<n;i++)
        {
            int val=prev1,val2=nums[i];
            if(i>=2)val2+=prev2;
            int cur=max(val,val2);
            prev2=prev1;
            prev1=cur;
        }
        return prev1;
    }
};
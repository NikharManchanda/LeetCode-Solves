class Solution {
public:
    int rec(int idx,vector<int>&nums,vector<int>&costs,vector<int>&dp){
        
        if(idx==nums.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int a,b,c;
        a=costs[0]+rec(idx+1,nums,costs,dp);
        int i=idx;
        while(i<nums.size() && nums[i]<=nums[idx]+6)
        {
           i++;
        }
        b=costs[1]+rec(i,nums,costs,dp);
        i=idx;
        while(i<nums.size() && nums[i]<=nums[idx]+29)
        {
           i++;
        }
        c=costs[2]+rec(i,nums,costs,dp);        
        return dp[idx]=min({a,b,c});
    }
    int mincostTickets(vector<int>& nums, vector<int>& costs) {
        
        // Rec+Mem
        
        // vector<int>dp(nums.size()+1,-1);
        // return rec(0,nums,costs,dp);
        
        // Tabular
        int n=nums.size();
        vector<int> dp(n+1,INT_MAX);
        dp[n]=0;
        for(int idx=n-1;idx>=0;idx--)
        {
            int a,b,c;
            a=costs[0]+dp[idx+1];
            int i=idx;
            while(i<nums.size() && nums[i]<=nums[idx]+6)
            {
               i++;
            }
            b=costs[1]+dp[i];
            i=idx;
            while(i<nums.size() && nums[i]<=nums[idx]+29)
            {
               i++;
            }
            c=costs[2]+dp[i];
            dp[idx]=min({a,b,c});
        }
        return dp[0];
    }
};
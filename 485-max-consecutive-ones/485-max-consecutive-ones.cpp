class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int x=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
                x++;
            else
            {
                ans=max(ans,x);
                x=0;
            }
        }
        ans=max(ans,x);
        return ans;
    }
};
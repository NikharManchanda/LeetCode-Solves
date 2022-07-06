class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        return max(robHelper(nums,1,n),robHelper(nums,0,n-1));
    }
private:
    int robHelper(vector<int>& nums,int l ,int r) {
        int n=r-l+1;
        
        int prev1=nums[l],prev2=0;
        
        for(int i=l+1;i<r;i++){
        
            int val=prev1,val2=nums[i];
            if(i>=2)val2+=prev2;
            int cur=max(val,val2);
            prev2=prev1;
            prev1=cur;
            
        }
        
        return prev1;
    }
};
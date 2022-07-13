class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto x: nums)
            sum+=x;
        if(target>sum || target<-sum)
            return 0;
        vector<int>prev(2*sum+1);
        prev[sum+nums[0]]=1;
        prev[sum-nums[0]]+=1;
        for(int i=1;i<nums.size();i++){
            vector<int> cur(2*sum+1);
            for(int j=0;j<2*sum+1;j++){
                if(prev[j]!=0){
                    cur[j+nums[i]]+=prev[j];
                    cur[j-nums[i]]+=prev[j];
                }
            }
            prev=cur;
        }
        return prev[target+sum];
    }
};
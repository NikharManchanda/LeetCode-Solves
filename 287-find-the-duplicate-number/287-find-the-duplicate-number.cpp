class Solution {
public:
    
    // int findDuplicate(vector<int>& nums) {
    //     while(nums[nums[0]]!=nums[0])
    //     {
    //         swap(nums[nums[0]],nums[0]);
    //     }
    //     return nums[0];
    // }
    
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[abs(nums[i])]<0)
                return abs(nums[i]);
            nums[abs(nums[i])]*=-1;
        }
        return -1;
    }
    
};
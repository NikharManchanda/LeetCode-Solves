class Solution {
public:
    // O(n) Space
    
    // int majorityElement(vector<int>& nums) {
    //     unordered_map<int,int> mp;
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         mp[nums[i]]++;
    //         if(mp[nums[i]]>nums.size()/2)
    //             return nums[i];
    //     }
    //     return -1;
    // }
    
    // Bank Algorithm
    int majorityElement(vector<int>& nums) {
        int ans=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++)
        {
            if(count==0)
                ans=nums[i];
            if(nums[i]==ans)
                count++;
            else
                count--;
        }
        return ans;
    }

};
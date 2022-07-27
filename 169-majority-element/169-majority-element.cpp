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
    
    // Sort O(nlogn) Space O(1)
//     int majorityElement(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int count=1,cur=nums[0];
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]==nums[i-1])
//                 count++;
//             else
                
//         }
//     }

    // Boyer-Moore Voting Algorithm O(n) Space O(1)
    int majorityElement(vector<int>& nums) {
        int ans;
        int count=0;
        for(int i=0;i<nums.size();i++)
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
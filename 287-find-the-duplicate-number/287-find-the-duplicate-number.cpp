class Solution {
public:
    
//     int findDuplicate(vector<int>& nums) {
//         while(nums[nums[0]]!=nums[0])
//         {
//             swap(nums[nums[0]],nums[0]);
//         }
//         return nums[0];
//     }
    
//     int findDuplicate(vector<int>& nums) {
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[abs(nums[i])]<0)
//                 return abs(nums[i]);
//             nums[abs(nums[i])]*=-1;
//         }
//         return -1;
//     }
    
//     // Method 3 BS
//     int findDuplicate(vector<int>& nums) {
//         auto small_or_equal = [&](int cur) {
//             int count = 0;
//             for (auto &num: nums) {
//                 if (num <= cur)
//                     count++;
//             }
//             return count;
//         };
        
//         int low = 1, high = nums.size();
//         int duplicate = -1;
//         while (low <= high)
//         {
//             int cur = (low + high) / 2;
            
//             if (small_or_equal(cur) > cur)
//             { 
//                 duplicate = cur;
//                 high = cur - 1;
//             } 
//             else
//             {
//                 low = cur + 1;
//             }
//         }
//         return duplicate;
//     }
    
    // Method 4 Set Bits Elegant 
    int findDuplicate(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<=30;i++)
        {
            int c=0;
            for(int j=0;j<nums.size();j++)
            {
                if((nums[j]&(1<<i))!=0)
                {
                    c++;
                }
            }
            for(int j=1;j<=nums.size()-1;j++)
            {
                if((j&(1<<i))!=0)
                    c--;
            }
            if(c>0)
                ans=ans+(1<<i);
        }
        return ans;
    }
    
};
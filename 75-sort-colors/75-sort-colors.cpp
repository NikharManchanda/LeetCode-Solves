class Solution {
public:
    // Space O(1) 2 Pass Solution 
    void sortColors(vector<int>& nums) {
        vector<int>c(3,0);
        for(int i=0;i<nums.size();i++)
        {
            c[nums[i]]++;
        }
        int l=0;
        for(int i=0;i<nums.size();i++)
        {
            while(c[l]==0)
                l++;
            if(c[l]!=0)
            {
                nums[i]=l;
                c[l]--;
            }
        }
        return ;
    }

//     void sortColors(vector<int>& nums) {
//         int low,mid,high;
//         // Entries from 0 up to (but not including) i are values less than mid,
//         // entries from i up to (but not including) j are values equal to mid,
//         // entries from j up to (and including) k are values not yet sorted, and
//         // entries from k + 1 to the end of the array are values greater than mid.
//         low=0,mid=0,high=nums.size()-1;

//         while(mid<=high)
//         {
//             if(nums[mid]==0)
//             {
//                 swap(nums[low],nums[mid]);
//                 low++;
//                 mid++;
//             }
//             else if(nums[mid]==1)
//             {
//                 mid++;
//             }
//             else
//             {
//                 swap(nums[mid],nums[high]);
//                 high--;
//             }
//         }
//     }
    
};
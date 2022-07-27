class Solution {
public:
    
    int findKthLargest(vector<int>& nums, int k) {
        int l=0,r=nums.size()-1;
        k=nums.size()-k;
        while(l<=r)
        {
            int idx= quick_select(nums,l,r);
            if(idx==k)
                nums[idx];
            if(idx<k)
                l=idx+1;
            else
                r=idx-1;
        }
        return nums[k];
    }
    int quick_select(vector<int>&nums,int l, int r){
        int i=l,j=l,pivot=r;
        while(j<pivot)
        {
            if(nums[j]<=nums[pivot])
            {
                swap(nums[j],nums[i]);
                i++;
            }
            j++;
        }
        swap(nums[i],nums[pivot]);
        return i;
    }
};
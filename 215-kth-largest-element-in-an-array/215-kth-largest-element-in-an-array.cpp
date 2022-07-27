class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       ios_base::sync_with_stdio(false);cin.tie(nullptr);
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
        int tmp_piv=(l+r)/2;
        swap(nums[tmp_piv],nums[r]);
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
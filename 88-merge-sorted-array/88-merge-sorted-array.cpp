class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int k=n+m-1,i=m-1,j=n-1;k>=0;)
        {
            if(j>=0 && i>=0)
            {
                if(nums1[i]>=nums2[j])
                    nums1[k--]=nums1[i--];
                else
                    nums1[k--]=nums2[j--];
            }
            else if(j>=0)
                nums1[k--]=nums2[j--];
            else if(i>=0)
                break;
        }
    }
};
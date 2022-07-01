class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        ios_base::sync_with_stdio(0); cin.tie(NULL);
        int l=1,r=1e9+5;
        int ans=-1;
        auto ok=[&](int mid){
          int c=0;
          for(int i=0;i<nums.size();i++)
          {
              c+=((nums[i]-1)/mid);
          }
          return c<=maxOperations;
        };  
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(ok(mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;

    }
};
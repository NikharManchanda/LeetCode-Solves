class Solution {
public:
    long long merge(vector<int>&arr,int l ,int mid,int r){
        int i=l,j=mid,k=0;
        vector<int> temp(r-l+1);
        long long count=0;
        for(int i=l;i<=mid-1;i++)
        {
            while(j<=r && arr[i]>2LL*arr[j])
                j++;
            count+=j-mid;
        }
        i=l,j=mid;
        while(i<=mid-1 && j<=r){
            if(arr[i]<=arr[j]){
                temp[k++]=arr[i++];
            }
            else{
                temp[k++]=arr[j++];
            }
        }
        while(i<=mid-1)
            temp[k++]=arr[i++];
        while(j<=r)
            temp[k++]=arr[j++];
        k=0;
        for(int i=l;i<=r;i++,k++)
            arr[i]=temp[k];
        return count;
    }
    long long invCount(vector<int>&arr,int l , int r){
        long long int inversions=0;
        if(l<r)
        {
            int mid=(l+r)/2;
            inversions+=invCount(arr,l,mid);
            inversions+=invCount(arr,mid+1,r);
            inversions+=merge(arr,l,mid+1,r);
        }
        return inversions;
    }
    int reversePairs(vector<int>& nums) {
        return invCount(nums,0,nums.size()-1);
    }
};
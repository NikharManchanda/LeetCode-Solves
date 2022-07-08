class Solution {
public:
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int n=matrix.size(),m=matrix[0].size();
    //     int l=0,r=n-1;
    //     int row=-1;
    //     while(l<=r)
    //     {
    //         int mid=(l+r)/2;
    //         if(matrix[mid][0]<=target)
    //         {
    //             row=mid;
    //             l=mid+1;
    //         }
    //         else
    //         {
    //             r=mid-1;
    //         }
    //     }
    //     if(row==-1)
    //         return 0;
    //     l=0,r=m-1;
    //     while(l<=r)
    //     {
    //         int mid=(l+r)/2;
    //         if(matrix[row][mid]==target)
    //             return 1;
    //         if(matrix[row][mid]<target)
    //         {
    //             l=mid+1;
    //         }
    //         else
    //         {
    //             r=mid-1;
    //         }
    //     }
    //     return 0;
    // }
    
    // Single BS
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo = 0;
        if(!matrix.size()) return false;
        int hi = (matrix.size() * matrix[0].size()) - 1;
        
        while(lo <= hi)
        {
            int mid = (lo + (hi - lo) / 2);
            if(matrix[mid/matrix[0].size()][mid % matrix[0].size()] == target)
            {
                return true;
            }
            if(matrix[mid/matrix[0].size()][mid % matrix[0].size()] < target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return false;
    }
};
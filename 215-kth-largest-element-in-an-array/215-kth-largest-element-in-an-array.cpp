class Solution {
public:
    
    int findKthLargest(vector<int>& nums, int k) {
        
        // priority_queue<int,vector<int>,greater<int> > pq;
        // for(int i=0;i<nums.size();i++)
        // {
        //     pq.push(nums[i]);
        //     if(pq.size()>k)
        //         pq.pop();
        // }
        // return pq.top();
        
        // priority_queue<int> pq(nums.begin(),nums.end());
        // for(int i=1;i<k;i++)
        // {
        //     pq.pop();
        // }
        // return pq.top();
        
        multiset<int> s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
            if(s.size()>k)
                s.erase(s.begin());
        }
        return *s.begin();
    }
};
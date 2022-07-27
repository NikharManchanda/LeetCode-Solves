class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        int ans=0;
        for(auto i: s)
        {
            if(s.find(i-1)==s.end())
            {
                int c=1;
                while(s.find(i+c)!=s.end())
                {
                    
                    c++;
                }
                ans=max(ans,c);
            }
        }
        return ans;
    }
};
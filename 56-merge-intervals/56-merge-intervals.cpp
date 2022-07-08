class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int> > ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<=intervals.size()-1;i++)
        {
            vector<int> cur=intervals[i];
            if(ans.back()[1]>=cur[0])
            {
                ans.back()[1]=max(ans.back()[1],cur[1]);
            }
            else
            {
                ans.push_back(cur);
            }
        }
        return ans;
    }
};
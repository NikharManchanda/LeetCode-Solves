class Solution {
public:
    int coinChange(vector<int>& coins, int n) {
        vector<int> ways(n+1,INT_MAX);
        ways[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(auto x: coins)
            {
                if(i-x>=0 && ways[i-x]!=INT_MAX)
                    ways[i]=min(ways[i],1+ways[i-x]);
            }
        }
        if(ways[n]==INT_MAX)
            return -1;
        return ways[n];
    }
};
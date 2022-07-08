class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cmax=0;
        int cmin=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            cmax=max(prices[i]-cmin,cmax);
            cmin=min(cmin,prices[i]);
        }
        return cmax;
    }
};
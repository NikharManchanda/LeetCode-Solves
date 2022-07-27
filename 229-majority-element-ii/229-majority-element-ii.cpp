class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=-1,num2=-1,c1=0,c2=0;
        for(auto x: nums){
            if(num1==x)
                c1++;
            else if(num2==x)
                c2++;
            else if(c1==0)
                num1=x,c1++;
            else if(c2==0)
                num2=x,c2++;
            else
                c1--,c2--;
        }
        c1=0,c2=0;
        for(auto x: nums)
        {
            if(x==num1)
                c1++;
            else if(x==num2)
                c2++;
        }
        int sz=nums.size();
        cout<<c1<<" "<<c2;
        if(c1>sz/3 && c2>sz/3)
            return {num1,num2};
        else if(c1>sz/3)
            return {num1};
        else if(c2>sz/3)
            return {num2};
        else
            return {};
    }
};
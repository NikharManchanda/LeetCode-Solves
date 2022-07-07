class Solution {
public:
    string reverseWords(string s) {
       stringstream stream(s);
        string cur;
        string ans;
        vector<string> temp;
        while(stream >> cur)
        {
            temp.push_back(cur);
        }
        reverse(temp.begin(),temp.end());
        for(auto x: temp)
        {
            ans+=" "+x;
        }
        return ans.substr(1);
    }
};
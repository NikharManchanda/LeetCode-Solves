class Solution {
public:
    string reverseWords(string s) {
       stringstream stream(s);
        string cur;
        string ans;
        vector<string> temp;
        while(stream >> cur)
        {
            if(ans!="")
                ans=cur+" "+ans;
            else
                ans=cur;
        }
        return ans;
    }
};
class Solution {
public:
    int strStr(string text, string pat) {
        int n=text.size(),m=pat.size();
        for(int i=0;i<=n-m;i++)
        {
            bool ok=1;
            for(int j=0;j<m;j++)
            {
                if(text[i+j]!=pat[j])
                {
                    ok=0;
                    break;
                }
            }
            if(ok)
                return i;
        }
        return -1;
    }
};
class Solution {
public:
    // Naive String Matching 
    
    // int strStr(string text, string pat) {
    //     int n=text.size(),m=pat.size();
    //     for(int i=0;i<=n-m;i++)
    //     {
    //         bool ok=1;
    //         for(int j=0;j<m;j++)
    //         {
    //             if(text[i+j]!=pat[j])
    //             {
    //                 ok=0;
    //                 break;
    //             }
    //         }
    //         if(ok)
    //             return i;
    //     }
    //     return -1;
    // }
    
    
    // Z function

    int strStr(string text, string pat) {
        int n=text.size(),m=pat.size();
        string s=pat+'$'+text;
        int z_length=n+m+1;
        int Z[z_length];
        Z[0]=0;
        int l=0,r=0;
        for(int i=1;i<z_length;i++)
        {
            if(r<i)
            {
                l=r=i;
                while(r<s.size() && s[r]==s[r-l])
                {
                    r++;
                }
                Z[i]=r-l;
                r--;
            }
            else
            {
                int pre_idx=i-l;
                int z_value=Z[pre_idx];
                if(Z[pre_idx]<r-i+1)
                {
                    Z[i]=Z[pre_idx];
                }
                else
                {
                    l=i;
                    while(r<s.size() && s[r]==s[r-l])
                        r++;
                    Z[i]=r-l;
                    r--;
                }
            }
        }
        for(int i=pat.size()+1;i<s.size();i++)
        {
            if(Z[i]==pat.size())
            {
                return i-1-pat.size();
            }
        }
        return -1;
    }
};
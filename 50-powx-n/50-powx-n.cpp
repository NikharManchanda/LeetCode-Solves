class Solution {
public:
    double myPow(double x,long long int n) {
        if(n==0)
            return 1;
        if(n<0)
        {   
            x=1/x;
            n=n*-1;
        }
        double res=myPow(x,n/2);
        return n%2?res*res*x:res*res;
    }
};
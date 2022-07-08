vector<int> Solution::repeatedNumber(const vector<int> &a) {
    long long int n=a.size();
    long long int sum1=0,sum2=0;
    for(int i=0;i<n;i++)
    {
        long long var=a[i];
        long long int tmp1=var-(i+1);
        long long int tmp2=var+(i+1);
        sum1+=tmp1*tmp2;
        sum2+=tmp1;
    }
    long long int dif=sum2,sum=sum1/sum2;
    long long int x,y;
    x=(sum+dif)/2,y=(sum-dif)/2;
    return {x,y};
}

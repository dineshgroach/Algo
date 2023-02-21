// Using 1D DP approach
int ncr(int n,int r)
{
    vector<int> res(r+1);
    res[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=min(i,r);j>0;j--)
        {
            res[j]=(res[j]+res[j-1])%1000000007;
        }
    }
    return res[r];
}

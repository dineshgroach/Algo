// finding factorial using dynamic programming
int fact(int n)
{
    vector<int> f(n+1);
    f[0]=f[1]=1;
    for(int i=2;i<=n;i++)
    {
        f[i]=i*f[i-1];
    }
    return f[n];
}

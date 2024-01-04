// Using Pre Computation to calculate the nCr fastly
const int MOD = 1e9 + 7;
const int N = 5000005;
int fac[N], qe[N];

int calcpower(int a, int b, int m)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % m;
        b /= 2;
        a = (a * a) % m;
    }
    return ans;
}

int l(int k)
{
    return calcpower(k, MOD - 2, MOD);
}

// Just Call this Function to initialize everything
void init()
{
    fac[0] = fac[1] = 1;
    for (int i = 2; i < N; i++)
    {
        fac[i] = fac[i - 1] * i;
        fac[i] %= MOD;
    }
    qe[N - 1] = l(fac[N - 1]);
    for (int i = N - 2; i >= 0; i--)
    {
        qe[i] = qe[i + 1] * (i + 1);
        qe[i] %= MOD;
    }
}

int nCr(int x, int y)
{
    if (y > x)
        return 0ll;
    int v = fac[x];
    v *= qe[y];
    v %= MOD;
    v *= qe[x - y];
    v %= MOD;
    return v;
}

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

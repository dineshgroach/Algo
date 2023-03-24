int countPartitions(int n, int d, vector<int> &arr)
{
    const int MOD = 1e9 + 7;
    int sum = accumulate(arr.begin(), arr.end(), 0LL);
    int m = d + sum;
    if(m%2)
    {
        return 0;
    }
    m = m / 2;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  // only 0,0 is true because we can use {},{0} for sum zero
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <=m; j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]) % MOD;
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}

class Solution{

	public:
	long long perfectSum(int arr[], int n, int sum)
	{
	long long MOD=1e9+7;
    long long m = sum;
    long long dp[n + 1][m + 1];
    long long cnt=0;
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
        if(i>0)
        {
            if(arr[i-1]==0)
            {
                cnt++;
            }
            dp[i][0]=1<<cnt;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] + dp[i - 1][j])%MOD;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return (dp[n][m]);
	}
	  
};

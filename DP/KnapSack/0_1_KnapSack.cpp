// 0 1 KnapSack GFG Problem

// Below the code using recursion and memoization in top-down DP
int blackbox(int n,int w,int wt[],int val[],vector<vector<int>>&dp)
{
    if(n==0||w==0)
    {
        return 0;
    }
    // To check if the value is not being memoized
    if(dp[n][w]!=-1)
    {
        return dp[n][w];
    }

    // If can include but choice is there to not include
    if(wt[n-1]<=w)
    {
        dp[n][w]=max(val[n-1]+blackbox(n-1,w-wt[n-1],wt,val,dp),blackbox(n-1,w,wt,val,dp));
        return dp[n][w];
    }

    // If we can include that element
    if(wt[n-1]>w)
    {
        dp[n][w]=blackbox(n-1,w,wt,val,dp);
    }
}

int knapSack(int W, int wt[], int val[], int n) 
{ 
    vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
    return blackbox(n,W,wt,val,dp);
}

// Below the iterative/tabulation or bottom up DP
int knapSack(int W, int wt[], int val[], int n) 
{ 
    vector<vector<int>>dp(n+1,vector<int>(W+1));
    for (int i = 0; i <=n; i++)
    {
        for (int j = 0; j <=W; j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
            else if(wt[i-1]<=j)
            {
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

// Space Optimized soultion because we are only using the 1D DP
int knapSack(int W, int wt[], int val[], int n) 
    { 
        int dp[W+1];
        memset(dp,0,sizeof(dp));
        for(int i = 1;i<= n;i++)
        {
            for(int w=W;w>=0;w--)
            {
                if(wt[i-1]<=w)
                {
                    dp[w]=max(dp[w],dp[w-wt[i-1]]+val[i-1]);
                }
            }
        }
        return dp[W];
    }

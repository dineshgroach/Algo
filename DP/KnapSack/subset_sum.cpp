class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();
        int m = sum;
        bool t[n + 1][m + 1];
        for (int i = 0; i < m+1; i++)
        {
            t[0][i] = false;
        }
        for (int i = 0; i < n+1; i++)
        {
            t[i][0] = true;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <=m; j++)
            {
                if(arr[i-1]<=j)
                {
                    t[i][j] = t[i-1][j - arr[i - 1]] || t[i - 1][j];
                }
                else
                {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        return (t[n][m]);
    }
};

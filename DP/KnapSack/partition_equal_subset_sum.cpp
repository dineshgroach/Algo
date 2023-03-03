class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long sum=0;
        for(auto i:nums)
        {
            sum+=i;
        }
        if(sum%2)
        {
            return 0;
        }
        int n=nums.size();
        int m=(sum/2);
        bool t[n+1][m+1];
        for(int i=0;i<=m;i++)
        {
            t[0][i]=0;
        }
        for(int i=0;i<=n;i++)
        {
            t[i][0]=1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if (nums[i - 1] <= j)
                {
                    t[i][j] = t[i-1][j - nums[i - 1]] || t[i - 1][j];
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

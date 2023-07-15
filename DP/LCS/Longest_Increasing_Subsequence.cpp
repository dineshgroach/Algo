// Memoize version(Top-Down) using DP : TC - O(N^2)
int lis(int n, vector<int> &a,vector<int> &dp)
    {
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < a[n])
            {
                ans = max(ans, lis(i, a,dp) + 1);
            }
        }
        return dp[n] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int ans=0;
        vector<int>dp(nums.size(),-1);
        for(int i=0;i<nums.size();i++)
        {
            ans=max(ans,lis(i,nums,dp));
        }
        return ans;
    }


// Iterative verison using DP : TC - O(N^2)
int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int>dp(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] and dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }

// Optimized Approach using Greedy and Binary Search : TC - O(NlonN) 
// Refer to YouTube to refersh the concept
int lengthOfLIS(vector<int>& nums) {
        vector<int>temp;
        for(auto it:nums)
        {
            if(temp.empty() or temp[temp.size()-1] < it)
            {
                temp.push_back(it);
            }
            else
            {
                auto itr = lower_bound(temp.begin(),temp.end(),it);
                *itr=it;
            }
        }
        return temp.size();
    }

// Optimized Approach using DP and Binary Search : TC - O(NlonN)
// Refer to CP-Algorithms for more clearity
int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        const int INF = 1e9;
        vector<int>dp(n+1,INF);
        dp[0]=-INF;
        for(int i = 0;i<n;i++)
        {
            int l = upper_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
            if(dp[l-1]<nums[i] && nums[i]<dp[l])
            {
                dp[l]=nums[i];
            }
        }
        int ans = 0;
        for(int i=0;i<=n;i++)
        {
            if(dp[i]<INF)
            {
                ans=i;
            }
        }
        return ans;
    }

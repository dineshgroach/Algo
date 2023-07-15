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

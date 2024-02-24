// Gives an array which shows that from the ith index a[i] length of suffix is also suffix considering overlapping as well

// Can also be use for patthern matching using conver string s = pattern + '#' + text, where '#' is some special character
// not in the string and this way can be used to find pattern prefix as well
vector<int> Z_Algorithm(string &s)
{
    int n = s.size();
    vector<int> ans(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if(i < r)
        {
            ans[i] = min(r - i, ans[i - l]);
        }
        while(i + ans[i] < n && s[ans[i]] == s[ans[i] + i])
        {
            ans[i]++;
        }
        if(i + ans[i] > r)
        {
            l = i;
            r = i + ans[i];
        }
    }
    return ans;
}

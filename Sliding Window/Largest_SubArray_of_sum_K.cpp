#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    ll i = 0, j = 0, ans = 0, sum = 0;
    while (j < n)
    {
        sum += v[j];
        if (sum < k)
        {
            j++;
        }
        else if (sum == k)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else
        {
            while (sum > k)
            {
                sum -= v[i];
                i++;
                if (sum == k)
                {
                    ans = max(ans, j - i + 1);
                }
            }
            j++;
        }
    }
    cout << ans << endl;
    return 0;
}

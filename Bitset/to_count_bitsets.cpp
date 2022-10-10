#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

// Time complexity O(logn)
int count_set_bits(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        if (n & 1 == 1)
        {
            cnt++;
        }
        n >>= 1;
    }
    return cnt;
}

// Time Complexity O(no of set bits) i.e. in worst case same as above one
int brian_kerninghan(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        cnt++;
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    // cout << brian_kerninghan(n);
    cout << __builtin_popcount(n);
    return 0;
}

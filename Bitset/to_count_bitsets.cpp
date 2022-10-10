#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

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
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    cout << count_set_bits(n);
    return 0;
}
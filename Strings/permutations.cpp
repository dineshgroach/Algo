#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void perm(string s, int l, int r)
{
    if (l == r)
    {
        cout << s << endl;
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(s[l], s[i]);
            perm(s, l + 1, r);
            swap(s[l], s[i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    perm(s, 0, n - 1);
    return 0;
}
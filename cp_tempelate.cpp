#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

// Pragmas -> for some optimization
#pragma GCC optimize("O3,unroll-loops")
#ifndef LOCAL_PROJECT
#pragma GCC target("avx2")
#endif

// Declearing Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;

// DEclearing Constants
constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9 + 7;

// Declearing Macros
#define F first
#define S second
#define Y Yes
#define N NO
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)
#define int long long

// Custom hash map -> to avoid hacking
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <typename T1, typename T2> // Key should be integer type
using custom_map = unordered_map<T1, T2, custom_hash>;

// Operator overloads for direct input and output
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}

template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}

template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << " " << p.second);
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

// To get size of container and avoid some error
template <typename T>
int32_t sz(T &container) { return static_cast<int32_t>(container.size()); }

// Some Mathematical functions
int GCD(int a, int b)
{
    return (__gcd(a, b));
}

int GCD_extended(int a, int b, int &x, int &y)
{
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1)
    {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

int LCM(int a, int b)
{
    return ((ll)a * b) / GCD(a, b);
}

int bpow(int x, int n)
{
    if (x == 0 and n == 0)
    {
        return 0;
    }
    int res = 1;
    while (n > 0)
    {
        if (n % 2)
        {
            res = (res * x) % MOD;
        }
        n = n / 2;
        x = (x * x) % MOD;
    }
    return res;
}

int ncr(int n, int r)
{
    vector<int> res(r + 1);
    res[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, r); j > 0; j--)
        {
            res[j] = (res[j] + res[j - 1]) % 1000000007;
        }
    }
    return res[r];
}

int fact(int n)
{
    vector<int> f(n + 1);
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i] = (i * f[i - 1]) % 1000000007;
    }
    return f[n];
}

bool chkpalindrome(string s)
{
    long long start = 0, end = s.length() - 1;
    while (start <= end)
    {
        if (s[start] != s[end])
        {
            return false;
            break;
        }
        start++;
        end--;
    }
    return true;
}

bool chkPowerof2(int n)
{
    if (n == 0)
    {
        return false;
    }
    return (ceil(log2(n)) == floor(log2(n)));
}

unsigned highestPowerof2(unsigned num)
{
    num |= num >> 1;
    num |= num >> 2;
    num |= num >> 4;
    num |= num >> 8;
    num |= num >> 16;
    return num ^ (num >> 1);
}

void solve()
{
    
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(12) << fixed;

    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}

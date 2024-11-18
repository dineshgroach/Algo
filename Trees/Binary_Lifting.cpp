#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        adj[i].push_back(x - 1);
        adj[x - 1].push_back(i);
    }
 
    vector<vector<int>> dp(n + 1, vector<int>(20, -1));
 
    auto dfs = [&](int node, int par, auto &&self) -> void
    {
        dp[node][0] = par;
        for (int i = 1; i < 20; i++)
        {
            if(dp[node][i - 1] != -1)
            {
                dp[node][i] = dp[dp[node][i - 1]][i - 1];
            }
        }
        for(auto& child:adj[node])
        {
            if(child == par) continue;
            self(child, node, self);
        }
    };
 
    dfs(0, -1,dfs);
 
    auto ans = [&](int node, int pos, auto &&self) -> int {
        if(node == -1 or pos <= 0)
        {
            return node;
        }
        for (int i = 19; i >= 0; i--)
        {
            if((pos >> i) & 1)
            {
                return self(dp[node][i], pos ^ (1 << i), self);
            }
        }
        return -1;
    };
 
    for (int i = 0; i < q; i++)
    {
        int node, height;
        cin >> node >> height;
        int sol = ans(node - 1, height, ans);
        cout << ((sol == -1) ? sol : (sol + 1)) << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<bool> vis;
vector<int> depth;
vector<int> height;

void dfs(int vertex, int par = 0)
{
    vis[vertex] = true;
    for (auto child : g[vertex])
    {
        if (child == par)
        {
            continue;
        }
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
        height[vertex] = max(height[vertex], height[child] + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    g.resize(n + 1);
    depth.resize(n + 1);
    height.resize(n + 1);
    vis.assign(n + 1, false);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << height[i] << " " << depth[i] << endl;
    }
    return 0;
}

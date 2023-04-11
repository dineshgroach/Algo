#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> g[N];
int par[N];

void dfs(int vertex, int p = -1)
{
    par[vertex] = p;
    for (int child : g[vertex])
    {
        if (child == p)
            continue;
        dfs(child, vertex);
    }
}

vector<int> path(int vertex)
{
    vector<int> ans;
    while (vertex != -1)
    {
        ans.push_back(vertex);
        vertex = par[vertex];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    int x, y;
    cin >> x >> y;
    vector<int> path_x = path(x);
    vector<int> path_y = path(y);
    int lca = -1;
    int len_min = min(path_x.size(), path_y.size());
    for (int i = 0; i < len_min; i++)
    {
        if (path_x[i] == path_y[i])
        {
            lca = path_x[i];
        }
        else
        {
            break;
        }
    }
    cout << lca << endl;
    return 0;
}

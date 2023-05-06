// Problem Link - https://www.codechef.com/problems/SNSOCIAL

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
const int INF = 1e9 + 10;

vector<vector<int>> val(N, vector<int>(N));
vector<vector<bool>> vis(N, vector<bool>(N));
vector<vector<int>> lev(N, vector<int>(N, INF));

int n, m;

vector<pair<int, int>> movements = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

bool isvalid(int x, int y)
{
    return x >= 0 and y >= 0 and x < n and y < m;
}

int bfs()
{
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mx = max(mx, val[i][j]);
        }
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (val[i][j] == mx)
            {
                q.push({i, j});
                lev[i][j] = 0;
                vis[i][j] = true;
            }
        }
    }
    int ans = 0;
    while (!q.empty())
    {
        auto v = q.front();
        int v_x = v.first;
        int v_y = v.second;
        q.pop();
        for (auto move : movements)
        {
            int child_x = move.first + v_x;
            int child_y = move.second + v_y;
            if (!isvalid(child_x, child_y))
                continue;
            if (vis[child_x][child_y])
                continue;
            q.push({child_x, child_y});
            lev[child_x][child_y] = lev[v_x][v_y] + 1;
            vis[child_x][child_y] = true;
            ans = max(ans, lev[child_x][child_y]);
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        val.assign(n, vector<int>(m));
        vis.assign(n, vector<bool>(m));
        lev.assign(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> val[i][j];
            }
        }
        cout << bfs() << endl;
    }
    return 0;
}

// Problem Link - https://www.codechef.com/problems/REVERSE

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;

vector<pair<int, int>> g[N];
vector<int> dist(N, INF);

int n, m;

int bfs()
{
    deque<int> q;
    q.push_back(1);
    dist[1] = 0;
    while (!q.empty())
    {
        int curr_v = q.front();
        q.pop_front();
        for (auto &child : g[curr_v])
        {
            int child_v = child.first;
            int wt = child.second;
            if (dist[curr_v] + wt < dist[child_v])
            {
                dist[child_v] = dist[curr_v] + wt;
                if (wt == 1)
                {
                    q.push_back(child_v);
                }
                else
                {
                    q.push_front(child_v);
                }
            }
        }
    }
    return dist[n] == INF ? -1 : dist[n];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x == y)
            continue;
        g[x].push_back({y, 0});
        g[y].push_back({x, 1});
    }
    cout << bfs() << endl;
    return 0;
}

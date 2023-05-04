// Basic Code of Breadth First Search
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> g[N];

vector<int> vis(N);
// Level Array is to calculate the level of the vertex
vector<int> level(N);

void bfs(int source)
{
    vis[source] = true;
    queue<int> q;
    q.push(source);
    while (!q.empty())
    {
        int curr_vertex = q.front();
        q.pop();
        for (auto child : g[curr_vertex])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = 1;
                level[child] = level[curr_vertex] + 1;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "Level[" << i << "] : " << level[i] << endl;
    }

    return 0;
}

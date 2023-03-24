// Raw code for the dfs - Depth First Search
const int N = 1e5+10;
vector<vector<int>> v(N);
vector<bool> visited(N);

void dfs(int vertex)
{
    // Take action on verten after entering the vertex
    visited[vertex] = true;
    for (int child : v[vertex])
    {
        // Take action on child before entering the child node
        if (visited[child])
        {
            continue;
        }
        dfs(child);
        // Take action on child after exiting the child node
    }
    // Take action on vertex before exiting the vertex
}


// To find the Connected Components in undirected graph using DFS
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int vertex)
{
    visited[vertex] = true;
    for (auto i : graph[vertex])
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    graph.resize((n + 1), vector<int>());
    visited.resize(n + 1, false);
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

// To find the cycle in an undirected graph using the DFS
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

bool dfs(int vertex, int parent)
{
    visited[vertex] = true;
    bool loop_check = false;
    for (auto i : graph[vertex])
    {
        if (visited[i] and i == parent)
        {
            continue;
        }
        if (visited[i])
        {
            return true;
        }
        loop_check |= dfs(i, vertex);
    }
    return loop_check;
}

int main()
{
    int n, e;
    cin >> n >> e;
    graph.resize((n + 1), vector<int>());
    visited.resize(n + 1, false);
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    bool cycle_check = false;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
        {
            continue;
        }
        if (dfs(i, -1))
        {
            cycle_check = true;
            break;
        }
    }
    if (cycle_check)
    {
        cout << "Cycle Exists" << endl;
    }
    else
    {
        cout << "No Cycle Detected" << endl;
    }
    return 0;
}

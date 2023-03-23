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

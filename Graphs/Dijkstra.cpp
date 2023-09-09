// Dijikstra Algorithm Stiver Approach using Set

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>>st;
        st.insert({0,S});
        vector<int>dist(V,1e9);
        dist[S]=0;
        while(!st.empty())
        {
            auto it=*st.begin();
            int dis = it.first;
            int node = it.second;
            st.erase(it);
            for(auto it:adj[node])
            {
                int adjnode = it[0];
                int adjwt = it[1];
                if(dis + adjwt<dist[adjnode])
                {
                    if(dist[adjnode]!=1e9)
                    {
                        st.erase({dist[adjnode],adjnode});
                    }
                    dist[adjnode]=dis+adjwt;
                    st.insert({dist[adjnode],adjnode});
                }
            }
        }
        return dist;
    }


// Using Luv's Video

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;

vector<pair<int, int>> g[N];


// This Algorithm is used to fine the shortest distance between the source node and all other nodes
void dijkstra(int source)
{
    vector<bool> vis(N, 0);
    vector<int> dist(N, INF);

    set<pair<int, int>> st;

    st.insert({0, source});
    dist[source] = 0;

    while (st.size() > 0)
    {
        auto node = *st.begin();
        int v = node.second;
        st.erase(st.begin());
        if (vis[v])
        {
            continue;
        }
        vis[v] = true;
        for (auto child : g[v])
        {
            int child_v = child.first;
            int wt = child.second;
            if (dist[v] + wt < dist[child_v])
            {
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
    }
    int source;
    cin >> source;
    dijkstra(source);
    return 0;
}

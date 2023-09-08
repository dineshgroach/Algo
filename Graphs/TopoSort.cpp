// Topological Sort using DFS

void dfs(vector<vector<int>>&adj,stack<int>&st,vector<bool>&vis,int node)
{
    vis[node]=true;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(adj,st,vis,it);
        }
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    vector<vector<int>>adj(nodes);
    for(auto it:graph)
    {
        adj[it[0]].push_back(it[1]);
    }
    stack<int>st;
    vector<bool>vis(nodes,false);
    for(int i=0;i<nodes;i++)
    {
        if(!vis[i])
        {
            dfs(adj,st,vis,i);
        }
    }
    vector<int>ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}


// Topological Sort using BFS 
vector<int> toposort(int n,vector<vector<int>>&adj)
    {
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++)
      {
        for(auto it:adj[i])
        {
          indegree[it]++;
        }
      }
      queue<int>q;
      for(int i=0;i<n;i++)
      {
        if(indegree[i]==0)
        {
          q.push(i);
        }
      }
      vector<int>topsort;
      while(!q.empty())
      {
        int x = q.front();
        q.pop();
        topsort.push_back(x);
        for(auto ver:adj[x])
        {
          indegree[ver]--;
          if(indegree[ver]==0)
          {
            q.push(ver);
          }
        }
      }
      return topsort;
    }

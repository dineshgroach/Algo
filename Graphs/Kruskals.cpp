// Krushkal Striver Coding Ninja Code
class DisjointSet
{
private:
    vector<int> size, parent;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            size[i] = 1;
            parent[i] = i;
        }
    }

    int findpar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findpar(parent[node]);
    }

    void unionbysize(int u, int v)
    {
        int par_u = findpar(u);
        int par_v = findpar(v);
        if (par_u == par_v)
            return;
        if (size[par_u] < size[par_v])
        {
            parent[par_u] = par_v;
            size[par_v] += size[par_u];
        }
        else
        {
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        }
    }
};

int kruskalMST(int n, vector<vector<int>> &edges)
{
	vector<pair<int,pair<int,int>>>adj;
	for(auto it:edges)
	{
		int u = it[0];
		int v = it[1];
		int wt = it[2];
		adj.push_back({wt,{u,v}});
	}
    // Sorting adjanceny list according to the edges of the weight
	sort(adj.begin(),adj.end());
	int mstwt = 0;
	DisjointSet ds(n);
	for(auto it:adj)
	{
		int wt = it.first;
		int u = it.second.first;
		int v = it.second.second;
		if(ds.findpar(u)!=ds.findpar(v))
		{
			mstwt+=wt;
			ds.unionbysize(u, v);
		}
	}
	return mstwt;
}


// Luv CP Series Code
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> parent(N);
vector<int> chk_size(N);

multiset<int> sizes;
// This algorithm use DSU to find the Minimum Spanning Tree
void make(int v)
{
    parent[v] = v;
    chk_size[v] = 1;
    sizes.insert(1);
}

int find(int v)
{
    if (parent[v] == v)
    {
        return v;
    }
    return parent[v] = find(parent[v]);
}

void merge(int a, int b)
{
    sizes.erase(sizes.find(chk_size[a]));
    sizes.erase(sizes.find(chk_size[b]));
    sizes.insert(chk_size[a] + chk_size[b]);
}

void do_union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        // Union By Size
        if (chk_size[a] < chk_size[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        merge(a, b);
        chk_size[a] += chk_size[b];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        make(i);
    }

    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({wt, {u, v}});
    }
    sort(edges.begin(), edges.end());

    int total_cost = 0;
    for (auto &edge : edges)
    {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if (find(u) == find(v))
        {
            continue;
        }
        do_union(u, v);
        total_cost += wt;
        cout << u << " " << v << endl;
    }
    cout << total_cost << endl;
    return 0;
}

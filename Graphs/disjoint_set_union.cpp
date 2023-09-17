// Disjoint Set Union Using Class

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

// working example
DisjointSet ds(7);
    ds.unionbysize(1, 2);
    ds.unionbysize(2, 3);
    ds.unionbysize(4, 5);
    ds.unionbysize(6, 7);
    ds.unionbysize(5, 6);
    if (ds.findpar(3) == ds.findpar(7))
    {
        cout << "Same" << endl;
    }
    else
    {
        cout << "Not Same" << endl;
    }
    ds.unionbysize(3, 7);
    if (ds.findpar(3) == ds.findpar(7))
    {
        cout << "Same" << endl;
    }
    else
    {
        cout << "Not Same" << endl;
    }


#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> parent(N);
vector<int> chk_size(N);
void make(int v)
{
    parent[v] = v;
    chk_size[v] = 1;
}

int find(int v)
{
    if (parent[v] == v)
    {
        return v;
    }
    // Path Compression
    return parent[v] = find(parent[v]);
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
        chk_size[a] += chk_size[b];
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        make(i);
    }
    while (k--)
    {
        int u, v;
        cin >> u >> v;
        do_union(u, v);
    }
    int connected_cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        if (find(i) == i)
        {
            connected_cnt++;
        }
    }
    cout << connected_cnt << endl;
    return 0;
}

// Better in-question implementation of this
int find(int v, vector<int> &par)
{
    if (par[v] == v)
    {
        return v;
    }
    return par[v] = find(par[v], par);
}

void make_union(int x, int y, vector<int> &par, vector<int> &siz)
{
    x = find(x, par);
    y = find(y, par);
    if (x != y)
    {
        if (siz[x] < siz[y])
        {
            swap(x, y);
        }
        par[y] = x;
        siz[x] += siz[y];
    }
}

void solve()
{
    int n, p, q;
    cin >> n >> p >> q;
    vector<int> p1(n + 1, 0), p2(n + 1, 0);
    vector<int> s1(n + 1, 1), s2(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        p1[i] = i;
        p2[i] = i;
    }
    for (int i = 0; i < p; i++)
    {
        int x, y;
        cin >> x >> y;
        make_union(x, y, p1, s1);
    }
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        make_union(x, y, p2, s2);
    }
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int x1 = find(i, p1);
            int y1 = find(j, p1);
            int x2 = find(i, p2);
            int y2 = find(j, p2);
            if (x1 != y1 and x2 != y2)
            {
                v.emplace_back(i, j);
                make_union(i, j, p1, s1);
                make_union(i, j, p2, s2);
            }
        }
    }
    cout << sz(v) << endl;
    for (auto &it : v)
    {
        cout << it.first << " " << it.second << endl;
    }
}

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

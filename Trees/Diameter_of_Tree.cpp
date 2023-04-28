#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
vector<int> depth(N, 0);

void dfs(int vertex, int par = -1)
{
    for (int child : g[vertex])
    {
        if (child == par)
        {
            continue;
        }
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    // To calculate the farthest Node from Node 1
    int mx_depth = -1;
    int mx_depth_node;
    for (int i = 1; i <= n; i++)
    {
        if (depth[i] > mx_depth)
        {
            mx_depth = depth[i];
            mx_depth_node = i;
        }
    }
    depth.assign(N, 0);
    // To calculate the farthest Node from above found farthest Node
    dfs(mx_depth_node);
    for (int i = 1; i <= n; i++)
    {
        if (depth[i] > mx_depth)
        {
            mx_depth = depth[i];
        }
    }
    cout << mx_depth << endl;
    return 0;
}

// Diameter of a Binary Tree
class Solution {
  public:
    // Below code finds the total number of nodes
    int find_height(Node *root, int &res)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l = find_height(root->left, res);
        int r = find_height(root->right, res);
        int height = 1 + max(l, r);
        res = max(res,1+l+r);
        return height;
    } 
    int diameter(Node* root) {
        if(root==NULL)
        {
            return 0;
        }
        int res = INT_MIN;
        int var = find_height(root, res);
        return res;
    }
};

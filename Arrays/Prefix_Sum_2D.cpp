#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> p(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            p[i][j] = v[i - 1][j - 1] + p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }

    // To use Ranger Query Updation in O(1) time with 1 base Indexing
    int row1, col1, row2, col2;
    cin >> row1 >> col1 >> row2 >> col2;

    int ans = p[row2 + 1][col2 + 1] - p[row1][col2 + 1] - p[row2 + 1][col1] + p[row1][col1];
    cout << ans << endl;
    return 0;
}

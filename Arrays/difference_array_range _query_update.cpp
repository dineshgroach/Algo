#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    // Initializing the main and difference array
    vector<int> v = {2, 3, 6, 12, 18, 15};
    int n = v.size();
    vector<int> diff(n + 2, 0);

    // populating the main array
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            diff[i] = v[i];
        }
        else
        {
            diff[i] = v[i] - v[i - 1];
        }
    }

    // Start updating the range
    int l = 2;
    int r = 5;
    int value = 4;
    diff[l] = diff[l] + value;
    diff[r + 1] = diff[r + 1] - value;

    // Now update the prefix from diff array into the main array
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            v[i] = diff[i];
        }
        else
        {
            // this line updates the value into main array
            v[i] = diff[i] + diff[i - 1];
            // this line is used to make prefix sum into the diff array
            diff[i] = diff[i] + diff[i - 1];
        }
    }

    // This code is used only to generated the prefix sum of the difference array
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            diff[i] = diff[i];
        }
        else
        {
            diff[i] = diff[i] + diff[i - 1];
        }
    }

    // To print the update value in the main array
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

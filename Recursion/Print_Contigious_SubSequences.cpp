#include <bits/stdc++.h>
using namespace std;

// To Print all the subsequences using Recursion

void printsub(int ind, vector<int> &ds, vector<int> v, int n)
{
    if (ind == n)
    {
        for (auto &it : ds)
        {
            cout << it << " ";
        }
        if (ds.size() == 0)
        {
            cout << "NULL" << endl;
        }
        cout << endl;
        return;
    }

    // Condition to add the element at particular index
    ds.push_back(v[ind]);
    printsub(ind + 1, ds, v, n);

    // Condition to NOT add the element at particular index
    ds.pop_back();
    printsub(ind + 1, ds, v, n);
}
int main()
{
  // Data Structure used to hold the add or not add condition
    vector<int> ds;
  
  // This is main array whose subsequences will be printed
    vector<int> v{4, 6, 8};
    int n = v.size();
    printsub(0, ds, v, n);
    return 0;
}

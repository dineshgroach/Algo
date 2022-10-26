#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int findmax(int a[], int n)
{
    int mx = a[0];
    for (int i = 0; i < n; i++)
    {
        if (mx < a[i])
        {
            mx = a[i];
        }
    }
    return mx;
}
void CountSort(int a[], int n)
{
    int mx;
    int *c;
    mx = findmax(a, n);
    c = new int[mx + 1];
    for (int i = 0; i < mx + 1; i++)
    {
        c[i] = 0;
    }
    for (int i = 0; i < mx + 1; i++)
    {
        c[a[i]]++;
    }
    int i = 0, j = 0;
    while (j < mx + 1)
    {
        if (c[j] > 0)
        {
            a[i++] = j;
            c[j]--;
        }
        else
        {
            j++;
        }
    }
    delete[] c;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int Arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    CountSort(Arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;
    return 0;
}
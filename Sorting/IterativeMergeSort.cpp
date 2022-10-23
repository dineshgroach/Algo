#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void Merge(int a[], int l, int mid, int h)
{
    int i, j, k;
    i = l;
    j = mid + 1;
    k = l;
    int b[h + 1];
    while (i <= mid && j <= h)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        b[k++] = a[i++];
    }
    while (j <= h)
    {
        b[k++] = a[j++];
    }
    for (int i = l; i <= h; i++)
    {
        a[i] = b[i];
    }
}

void IterativeMergeSort(int a[], int n)
{
    int p;
    for (p = 2; p <= n; p = p * 2)
    {
        for (int i = 0; i + p - 1 < n; i = i + p)
        {
            int l = i;
            int h = i + p - 1;
            int mid = (l + h) / 2;
            Merge(a, l, mid, h);
        }
    }
    if (p / 2 < n)
    {
        Merge(a, 0, p / 2 - 1, n - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int Arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    IterativeMergeSort(Arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;
    return 0;
}
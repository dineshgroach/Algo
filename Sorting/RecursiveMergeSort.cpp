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
void RecursiveMergeSort(int a[], int l, int h)
{
    if (l < h)
    {
        int mid = l + (h - l) / 2;
        RecursiveMergeSort(a, l, mid);
        RecursiveMergeSort(a, mid + 1, h);
        Merge(a, l, mid, h);
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int Arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    RecursiveMergeSort(Arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;
    return 0;
}
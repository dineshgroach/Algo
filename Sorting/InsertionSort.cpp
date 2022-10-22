#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

// Time Complexity : Best = O(n),General = O(n^2)
void InsertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j;
        j = i - 1;
        int x = a[i];
        while (j >= 0 && a[j] > x)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int Arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    InsertionSort(Arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;
    return 0;
}
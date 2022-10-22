#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

// Time Complexity : Best = O(n^2),General = O(n^2)
void SelectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int k = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[k])
            {
                k = j;
            }
        }
        swap(a[k], a[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int Arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    SelectionSort(Arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;
    return 0;
}
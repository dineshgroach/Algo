#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

// Time Complexity : Best = O(n),General = O(n^2)
void BubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                flag = true;
            }
        }
        if (!flag)
        {
            break;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int Arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    BubbleSort(Arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;
    return 0;
}
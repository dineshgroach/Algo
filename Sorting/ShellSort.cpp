#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void ShellSort(int A[], int n)
{
    for (int gap = n / 2; gap >= 1; gap /= 2)
    {
        for (int j = gap; j < n; j++)
        {
            int temp = A[j];
            int i = j - gap;
            while (i >= 0 && A[i] > temp)
            {
                A[i + gap] = A[i];
                i = i - gap;
            }
            A[i + gap] = temp;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int Arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    ShellSort(Arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

// Quick Sort using INT_MAX or INFINITY
int partitionA(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low;
    int j = high;

    do
    {
        // Increment i as long as elements are smaller/equal to pivot
        do
        {
            i++;
        } while (A[i] <= pivot);

        // Decrement j as long as elements are larger than pivot
        do
        {
            j--;
        } while (A[j] > pivot);

        if (i < j)
        {
            swap(A[i], A[j]);
        }
    } while (i < j);

    swap(A[low], A[j]);
    return j;
}

void QuickSortA(int A[], int low, int high)
{
    if (low < high)
    {
        int j = partitionA(A, low, high);
        QuickSortA(A, low, j);
        QuickSortA(A, j + 1, high);
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int Arr[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3, INT32_MAX};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    QuickSortA(Arr, 0, n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;
    return 0;
}
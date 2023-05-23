#include <bits/stdc++.h>
using namespace std;

// Function to partition
int Partition(vector<int> &v, int low, int high)
{
    int pivot = v[low];
    int i = low, j = high;
    while (i < j)
    {
        while (v[i] <= pivot and i <= high - 1)
        {
            i++;
        }
        while (v[j] > pivot and j >= low - 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(v[i], v[j]);
        }
    }
    // Swapping position of pivot such left of it are smaller elements and
    // right of are greter elements
    swap(v[low], v[j]);
    return j;
}

// Function to call the Quick Sort
void QuickSort(vector<int> &v, int low, int high)
{
    if (low < high)
    {
        int partition_index = Partition(v, low, high);
        QuickSort(v, low, partition_index - 1);
        QuickSort(v, partition_index + 1, high);
    }
}

int main()
{
    vector<int> v = {4, 6, 2, 5, 7, 9, 1, 3};

    // Vector Before Quick Sort
    for (auto &it : v)
    {
        cout << it << " ";
    }
    cout << endl;

    // Now applying the Quick sort
    QuickSort(v, 0, v.size() - 1);

    // Vector After Quick Sort
    for (auto &it : v)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}

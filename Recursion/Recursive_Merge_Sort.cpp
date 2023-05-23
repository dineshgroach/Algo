#include <bits/stdc++.h>
using namespace std;

// Function to Merge
void Merge(vector<int> &v, int low, int high, int mid)
{
    // Temporary Vector to Store the Sorted Value
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    // Loop to compare and add elements in temporary vector
    while (left <= mid and right <= high)
    {
        if (v[left] <= v[right])
        {
            temp.push_back(v[left]);
            left++;
        }
        else
        {
            temp.push_back(v[right]);
            right++;
        }
    }

    // Loop to add the left out elements
    while (left <= mid)
    {
        temp.push_back(v[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(v[right]);
        right++;
    }

    // Loop to place those sorted elements into main vector
    for (int i = low; i <= high; i++)
    {
        v[i] = temp[i - low];
    }
}

// Function for the Merge Sort
void MergeSort(vector<int> &v, int low, int high)
{
    // Termination Condtion
    if (low == high)
    {
        return;
    }

    // Finding MID to divide the vector into two parts
    int mid = (low + high) / 2;
    MergeSort(v, low, mid);
    MergeSort(v, mid + 1, high);

    // After Divding Merging the two array
    Merge(v, low, high, mid);
}

int main()
{
    vector<int> v = {3, 4, 2, 1, 1, 8, 9, 6};

    // Vector Before Merge Sort
    for (auto &it : v)
    {
        cout << it << " ";
    }
    cout << endl;

    // Now applying the merge sort
    MergeSort(v, 0, v.size() - 1);

    // Vector After Merge Sort
    for (auto &it : v)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}

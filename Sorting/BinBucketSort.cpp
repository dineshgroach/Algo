#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int Max(int A[], int n)
{
    int max = -32768;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

// Linked List node
class Node
{
public:
    int value;
    Node *next;
};

void Insert(Node **ptrBins, int idx)
{
    Node *temp = new Node;
    temp->value = idx;
    temp->next = nullptr;

    if (ptrBins[idx] == nullptr)
    { // ptrBins[idx] is head ptr
        ptrBins[idx] = temp;
    }
    else
    {
        Node *p = ptrBins[idx];
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

int Delete(Node **ptrBins, int idx)
{
    Node *p = ptrBins[idx]; // ptrBins[idx] is head ptr
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    delete p;
    return x;
}

void BinSort(int A[], int n)
{
    int max = Max(A, n);

    // Create bins array
    Node **bins = new Node *[max + 1];

    // Initialize bins array with nullptr
    for (int i = 0; i < max + 1; i++)
    {
        bins[i] = nullptr;
    }

    // Update count array values based on A values
    for (int i = 0; i < n; i++)
    {
        Insert(bins, A[i]);
    }

    // Update A with sorted elements
    int i = 0;
    int j = 0;
    while (i < max + 1)
    {
        while (bins[i] != nullptr)
        {
            A[j++] = Delete(bins, i);
        }
        i++;
    }

    // Delete heap memory
    delete[] bins;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int Arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    BinSort(Arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Using deque - Least Recently Used - Page Replacement Algo
int main()
{
    int memorySize;
    cin >> memorySize;

    vector<int> v = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};

    deque<int> dq(memorySize);
    int hits = 0, pageFaults = 0;
    deque<int>::iterator itr;
    dq.clear();
    for(int ele:v)
    {
        itr = find(dq.begin(), dq.end(), ele);
        if(!(itr != dq.end()))
        {
            pageFaults++;
            if(dq.size() == memorySize)
            {
                dq.erase(dq.begin());
                dq.push_back(ele);
            }
            else
            {
                dq.push_back(ele);
            }
        }
        else
        {
            dq.erase(itr);
            dq.push_back(ele);
        }
    }
    cout << "Total Hits : " << hits << endl;
    cout << "Total Page Faults : " << pageFaults << endl;
    return 0;
}

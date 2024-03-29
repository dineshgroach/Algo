// This is the code from the Codeforces ITMO University used to create segment tree for an array where we can 
// perform two operations in query 1. Update a value 2. Get sum from range ( L to R)

// We can modify the code as well as to perform some other functions as well such as minimum,maximum,gcd,bitwise operator
// assocaitive operator like (including modulo multiplication, matrix multiplication, etc.) just change the sum function
// to the desired functions as well

#include <bits/stdc++.h>
using namespace std;

class SegmentTree 
{
private:
    int size;
    vector<long long> sums;

public:
    void init(int n)
    {
        size = 1;
        while(size < n)
        {
            size *= 2;
        }
        sums.assign(2 * size, 0LL);
    }

    void build(vector<int>&v,int x,int lx,int rx)
    {
        if(rx-lx == 1)
        {
            if(lx < (int)v.size())
            {
                sums[x] = v[lx];
            }
            return;
        }
        int mid = (lx + rx) / 2;
        build(v, 2 * x + 1, lx, mid);
        build(v, 2 * x + 2, mid, rx);
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void build(vector<int>&v)
    {
        build(v, 0, 0, size);
    }

    void set(int i,int v,int x,int lx,int rx)
    {
        if(rx - lx == 1)
        {
            sums[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if(i < mid)
        {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else
        {
            set(i, v, 2 * x + 2,mid, rx);
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void set(int i,int v)
    {
        set(i, v, 0, 0, size);
    }

    long long sum(int l,int r,int x,int lx,int rx)
    {
        if(lx >= r || rx <= l)
        {
            return 0;
        }
        if(lx>=l and rx<=r)
        {
            return sums[x];
        }
        int mid = (lx + rx) / 2;
        long long sum1 = sum(l, r, 2 * x + 1, lx, mid);
        long long sum2 = sum(l, r, 2 * x + 2, mid, rx);
        return sum1 + sum2;
    }

    long long sum(int l,int r)
    {
        return sum(l, r, 0, 0, size);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    SegmentTree st;
    st.init(n);

    vector<int> v(n);

    for(auto &it:v)
    {
        cin >> it;
    }

    st.build(v);

    while(m--)
    {
        int op;
        cin >> op;
        if(op==1)
        {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << st.sum(l, r) << endl;
        }
    }
    return 0;
}

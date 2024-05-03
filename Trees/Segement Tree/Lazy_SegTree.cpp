// In this below specific code addition is happening over the range of previous values in query range if want to directly 
// override the values then refer to this link  
// https://github.com/shivam-bhadani/Competitive-Codes/blob/master/Recursive%20Lazy%20Segment%20Tree.CPP
// or modify below tempelate
class SegTree
{
public:
    vector<int> st;
    vector<int> lazy;
    vector<bool> isLazy;
    int ID = 0; // change this
    int n = 0;
    SegTree(int s)
    {
        n = s;
        st.assign(4 * n + 5, ID);
        lazy.assign(4 * n + 5, ID);
        isLazy.assign(4 * n + 5, false);
    }

    void merge(int &curr, int &a, int &b)
    { // change this
        curr = a + b;
    }

    void propagate(int node, int L, int R)
    { // change this
        if (L != R)
        {
            isLazy[2 * node] = true;
            isLazy[2 * node + 1] = true;
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        st[node] += (R - L + 1) * lazy[node];
        lazy[node] = ID;
        isLazy[node] = false;
    }

    void Build(int node, int L, int R, vector<int> &arr)
    {
        if (L == R)
        {
            st[node] = arr[L];
            return;
        }
        int M = (L + R) / 2;
        Build(2 * node, L, M, arr);
        Build(2 * node + 1, M + 1, R, arr);
        merge(st[node], st[2 * node], st[2 * node + 1]);
    }

    void pUpdate(int node, int L, int R, int pos, int val)
    {
        if (L == R)
        {
            st[node] += val; // Change here to add with existing value
            return;
        }
        int M = (L + R) / 2;
        if (isLazy[2 * node])
        {
            propagate(2 * node, L, M);
        }
        if (isLazy[2 * node + 1])
        {
            propagate(2 * node + 1, M + 1, R);
        }
        if (pos <= M)
        {
            pUpdate(2 * node, L, M, pos, val);
        }
        else
        {
            pUpdate(2 * node + 1, M + 1, R, pos, val);
        }
        merge(st[node], st[2 * node], st[2 * node + 1]);
    }

    void Update(int node, int L, int R, int lo, int hi, int val)
    {
        if (R < lo || L > hi)
        {
            return;
        }
        if (lo <= L && R <= hi)
        {
            isLazy[node] = true;
            lazy[node] += val; // Change here to add with existing value
            propagate(node, L, R);
            return;
        }
        int M = (L + R) / 2;
        if (isLazy[2 * node])
        {
            propagate(2 * node, L, M);
        }
        if (isLazy[2 * node + 1])
        {
            propagate(2 * node + 1, M + 1, R);
        }
        Update(2 * node, L, M, lo, hi, val);
        Update(2 * node + 1, M + 1, R, lo, hi, val);
        merge(st[node], st[2 * node], st[2 * node + 1]);
    }

    int Query(int node, int L, int R, int lo, int hi)
    {
        if (R < lo || L > hi)
        {
            return ID;
        }
        if (lo <= L && R <= hi)
        {
            return st[node];
        }
        int M = (L + R) / 2;
        if (isLazy[2 * node])
        {
            propagate(2 * node, L, M);
        }
        if (isLazy[2 * node + 1])
        {
            propagate(2 * node + 1, M + 1, R);
        }
        int lft = Query(2 * node, L, M, lo, hi);
        int rght = Query(2 * node + 1, M + 1, R, lo, hi);
        int curr = ID;
        merge(curr, lft, rght);
        return curr;
    }

    int pQuery(int node, int L, int R, int pos)
    {
        if (L == R)
        {
            return st[node];
        }
        int M = (L + R) / 2;
        if (isLazy[2 * node])
        {
            propagate(2 * node, L, M);
        }
        if (isLazy[2 * node + 1])
        {
            propagate(2 * node + 1, M + 1, R);
        }
        if (pos <= M)
        {
            return pQuery(2 * node, L, M, pos);
        }
        else
        {
            return pQuery(2 * node + 1, M + 1, R, pos);
        }
    }

    void build(vector<int> &arr)
    {
        Build(1, 1, n, arr);
    }

    void update(int pos, int val)
    {
        pUpdate(1, 1, n, pos, val);
    }

    void update(int l, int r, int val)
    {
        Update(1, 1, n, l, r, val);
    }

    int query(int lo, int hi)
    {
        return Query(1, 1, n, lo, hi);
    }

    int query(int pos)
    {
        return pQuery(1, 1, n, pos);
    }
};

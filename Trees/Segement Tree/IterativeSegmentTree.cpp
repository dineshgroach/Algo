class SegmentTree
{
public:
    vector<int> segs;
    int size = 0;
    // default initialization
    int ID = 1e9;

    SegmentTree(int sz)
    {
        segs.assign(2 * sz, ID);
        size = sz;
    }

    // type of opr to perform
    int comb(int a, int b)
    {
        return min(a, b);
    }

    void upd(int idx, int val)
    {
        segs[idx += size] = val;
        for (idx >>= 1; idx; idx >>= 1)
            segs[idx] = comb(segs[idx << 1], segs[idx << 1 | 1]);
    }

    int query(int l, int r)
    {
        int lans = ID, rans = ID;
        for (l += size, r += size + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                lans = comb(lans, segs[l++]);
            if (r & 1)
                rans = comb(segs[--r], rans);
        }
        return comb(lans, rans);
    }
};

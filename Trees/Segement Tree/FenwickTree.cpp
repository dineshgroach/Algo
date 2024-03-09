// FenwickTree is always 1's based index, so change index accordingly
class FenwickTree
{
private:
    vector<int> bit;
    int n;

public:
    FenwickTree(int n)
    {
        bit = vector<int>(n + 1, 0);
        this->n = n;
    }

    int sum(int idx)
    {
        int ans = 0;
        for (; idx > 0; idx -= (idx & -idx))
        {
            ans += bit[idx];
        }
        return ans;
    }

    int query(int l,int r)
    {
        if(l > r)
        {
            return 0;
        }
        return sum(r) - sum(l - 1);
    }

    void update(int idx,int val)
    {
        for (; idx <= n; idx += (idx & -idx))
        {
            bit[idx] += val;
        }
    }
};

// if the values in the array is <=  n, then good otherwise have to use the path compression
// basically in sorted order map the array values with there index and then to use in below following ways
auto arr = nums;
sort(arr.begin(),arr.end());
auto find = [&](int x)
{
    return lower_bound(arr.begin(),arr.end(),x) - arr.begin() + 1;
};

// if want to use functionality of less than or more than element x then simply update every occurence with 1 and 
// perform regular query

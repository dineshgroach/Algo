class SegmentTree{
    int seg[4*100000];
    public:
    void build(int ind, int low, int high, vector<int>&nums){
        if(low==high){
            seg[ind] = nums[low];
            return;
        }
        int mid = (low+high)/2;
        build(2*ind+1,low,mid,nums);
        build(2*ind+2,mid+1,high,nums);
        seg[ind] = max(seg[2*ind+1],seg[2*ind+2]);
    }
    int rangeQuery(int low, int high, int l, int r, int ind){
        if(low>=l && high<=r){
            return seg[ind];
        }
        if(r<low || l>high){
            return INT_MIN;
        }
        int mid = low + (high-low)/2;
        return max(rangeQuery(low,mid,l,r,2*ind+1),rangeQuery(mid+1,high,l,r,2*ind+2));
    }
};

// example case to build - st.build(0,0,n-1,nums);
// to perfrom the query - st.rangeQuery(0,n-1,i,i+k-1,0)

    #include <ext/pb_ds/assoc_container.hpp> // Common file
    #include <ext/pb_ds/tree_policy.hpp>
    #include <functional> // for less
    #include <iostream>
    using namespace __gnu_pbds;
    using namespace std;
    template<class T> using ordered_set =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

// example decleration
    ordered_set<int>s;

// main operations: find_by_order() and order_of_key(). The first returns an iterator to the k-th largest element (counting 
// from zero), the second — the number of items in a set that are strictly smaller than our item

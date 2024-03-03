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

// if want to store the duplicate as well then try to use pbds with pairs Try pbds with pairs, insert{a[i],i}.
// find number of values less than equal to some x in pbds with pairs. s.order_of_key({x, n+1})
// where n=number of elements in array , another way to do same is to use ordered multiset

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

// example decleration rest features are same
    ordered_multiset<int>s;

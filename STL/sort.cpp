// To sort in way to put even element first and odd elements afterwards

sort(v.begin(), v.end(), [](int x, int y)
         { return x % 2 < y % 2; });

//  To sort the elements of a vector and return their sorted array in index in vector
vector<ll> o(n);
    iota(o.begin(), o.end(), 0);// iota function make the vector contigioulsy increasing like 0,1,2,3.. and so on
    sort(o.begin(), o.end(), [&](auto x, auto y)// if array is 2 3 1(p vector) and the o(vector) is 3,1,2 i.e index of sorted postions
         { return p[x] < p[y]; });

// Code to create set in which greater value is at top using custom sort
auto cmp = [](pair<int, int> const &x, pair<int, int> const &y)
{
    return x > y;
};
set<pair<int, int>, decltype(cmp)> a(cmp);

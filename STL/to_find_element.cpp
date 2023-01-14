// To find the minimum element in a given range
int mn = *min_element(v.begin(), v.end());

// To find the positon of an element in a given range
auto pos = find(v.begin(), v.end(), mn); // it return the iterator that's why auto keyword

// To find the distance between two iterators
cnt += distance(v.begin(), pos);

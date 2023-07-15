// To erase a all the ocurrence of a particular number from an array and concetnate the remaining part
vector<int> v{1, 2, 3, 4, 5, 6};
	auto b = v;
	b.erase(std::remove(b.begin(), b.end(), 4), b.end());

// Output - 1 2 3 5 6

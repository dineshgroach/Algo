// To sort in way to put even element first and odd elements afterwards

sort(v.begin(), v.end(), [](int x, int y)
         { return x % 2 < y % 2; });

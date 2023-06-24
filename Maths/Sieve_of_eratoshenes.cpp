const int N = 1e5;
    vector<bool> isPrime(N, true);
    // Note 0,1 are not Prime Numbers
    for (int i = 2; i * i < N; i++)
    {
        if(isPrime[i])
        {
            for (int j = i*i; j < N; j+=i)
            {
                isPrime[j] = false;
            }
        }
    }

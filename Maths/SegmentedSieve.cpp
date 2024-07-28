// To get the prime number betweent the range L and R
vector<bool> sieve(int n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if(isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

vector<bool> getPrimesInRange(long long L,long long R)
{
    vector<bool> prime = sieve(sqrt(R));
    vector<bool> isPrime(R - L + 1, true);
    for (long long i = 2; i * i<= R; i++)
    {
        if(!prime[i])
        {
            for (int j = max(i * i, (L + i -1)/(i * i)); j <= R; j += i)
            {
                isPrime[j - L] = false;
            }
        }
    }
    if(L == 1)
        isPrime[0] = false;
    return isPrime;
}

// How to print the answer
vector<bool> ans = getPrimesInRange(40,50);
for(int i = 0; i < ans.size(); i++)
{
  if(ans[i] == true)
    cout << 40 + i << ' ';
}

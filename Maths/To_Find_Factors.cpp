// Here in below function we are storing the factors with their frequency
void calc(int n, map<int, int> &m)
{
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            n /= i;
            m[i]++;
        }
    }
    if (n > 1)
    {
        m[n]++;
    }
}

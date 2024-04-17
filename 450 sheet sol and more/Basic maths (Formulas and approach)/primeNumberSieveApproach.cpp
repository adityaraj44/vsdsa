// Sieve of Eratosthenes theorem

int countPrimes(int n)
{
    // sieve of eratosthenes

    int count = 0;
    vector<bool> prime(n + 1, true);

    prime[0] = prime[1] = false;

    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            count++;

            for (int j = 2 * i; j < n; j = j + i)
            {
                prime[j] = false;
            }
        }
    }
    return count;
}

// time complexity O(nlog(log n))
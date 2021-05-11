class Solution {
public:
    bool prime[5000005];
    void seive(int n)
    {
        memset(prime, true, sizeof(prime));
        for(int i = 2; i * i <= n; i++)
        {
            if(prime[i] == true)
            {
                for(int j = i * i; j <= n; j += i)
                {
                    prime[j] = false;
                }
            }

        }
    }
    int countPrimes(int n) 
    {
        if(n == 0 || n == 1)
        {
            return 0;
        }
        seive(n);
        int count = 0;
        for(int i = 2; i <= n - 1; i++)
        {
            if(prime[i] == true)
            {
                count++;
            }
        }
        return count;
    }
};

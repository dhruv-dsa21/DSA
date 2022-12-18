class Solution
{
    public:
        bool isPrime(int n)
        {
           	// Corner cases
            if (n <= 1)
                return false;
            if (n <= 3)
                return true;

            if (n % 2 == 0 || n % 3 == 0)
                return false;

            for (int i = 5; i * i <= n; i = i + 6)
                if (n % i == 0 || n % (i + 2) == 0)
                    return false;

            return true;
        }
    void primeFactors(int &ans, int n)
    {
        if (n == 4 || isPrime(n))
        {
            ans = n;
            return;
        }
        int c = 2;
        int sum = 0;
        while (n > 1)
        {
            if (n % c == 0)
            {
                sum += c;
                n /= c;
            }
            else c++;
        }
        primeFactors(ans, sum);
        return;
    }

    int smallestValue(int n)
    {
        int ans;
        primeFactors(ans, n);
        return ans;
    }
};
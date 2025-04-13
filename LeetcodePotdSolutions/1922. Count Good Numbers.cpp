class Solution
{
public:
    const int mod = 1e9 + 7;
    long long Pow(long long a, long long b)
    {
        if (b == 0)
            return 1;
        if (b == 1)
            return a;
        long long ans = 1;
        if (b & 1)
        {
            ans = (ans * a) % mod;
        }
        long long val = Pow(a, b / 2) % mod;
        val = (val * val) % mod;
        ans = (ans * val) % mod;
        return ans;
    }
    int countGoodNumbers(long long n)
    {
        long long odd = n / 2;
        long long even = n - odd;
        long long ans = Pow(5, even) % mod;
        ans = (ans * Pow(4, odd)) % mod;
        return ans;
    }
};
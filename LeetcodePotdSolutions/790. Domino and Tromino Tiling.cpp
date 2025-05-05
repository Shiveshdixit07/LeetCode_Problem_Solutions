class Solution
{
public:
    const int mod = 1e9 + 7;
    long long dp[1001];
    int numTilings(int n)
    {
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            if (i - 1 >= 0)
                dp[i] += 2 * dp[i - 1];
            dp[i] %= mod;
            if (i - 3 >= 0)
                dp[i] += dp[i - 3];
            dp[i] %= mod;
        }

        return dp[n];
    }
};
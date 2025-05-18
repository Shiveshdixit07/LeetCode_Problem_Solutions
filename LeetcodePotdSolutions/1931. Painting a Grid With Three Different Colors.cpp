class Solution
{
public:
    const int mod = 1e9 + 7;
    int dp[1 << 10][1 << 10];

    int solve(int i, int j, int prevMask, int CurrMask, int n, int m)
    {
        if (i == n)
            return 1;
        if (dp[i][prevMask] != -1 && j == 0)
            return dp[i][prevMask];
        if (j == m)
            return solve(i + 1, 0, CurrMask, 0, n, m);
        long long ans = 0;
        for (int I = 1; I <= 3; I++)
        {
            if (((prevMask >> (2 * j)) & 3) != I &&
                (j == 0 || ((CurrMask >> (2 * j - 2)) & 3) != I))
            {
                ans +=
                    solve(i, j + 1, prevMask, CurrMask | (I << (2 * j)), n, m);
                ans = ans % mod;
            }
        }
        if (j == 0)
            dp[i][prevMask] = ans;
        return ans;
    }
    int colorTheGrid(int m, int n)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, 0, n, m);
    }
};
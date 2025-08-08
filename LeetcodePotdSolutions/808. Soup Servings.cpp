class Solution
{
public:
    vector<vector<double>> dp;
    double solve(int a, int b)
    {
        if (a <= 0 && b <= 0)
            return 0.5;
        if (a <= 0)
            return 1.0;
        if (b <= 0)
            return 0.0;

        if (dp[a][b] != -1.0)
            return dp[a][b];

        double ans = 0;
        ans += (0.25 * solve(a - 100, b));
        ans += (0.25 * solve(a - 75, b - 25));
        ans += (0.25 * solve(a - 50, b - 50));
        ans += (0.25 * solve(a - 25, b - 75));
        return dp[a][b] = ans;
    }
    double soupServings(int n)
    {
        if (n >= 5000)
            return 1.0;
        dp.resize(n + 1, vector<double>(n + 1, -1.0));
        return solve(n, n);
    }
};
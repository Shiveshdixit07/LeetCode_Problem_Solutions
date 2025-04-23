class Solution
{
public:
#define ll long long
    ll fact[10001];

    const int mod = 1e9 + 7;
    ll Pow(ll a, ll b)
    {
        ll ans = 1;
        while (b > 0)
        {
            if (b & 1)
            {
                ans = (ans * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return ans % mod;
    }
    ll modularInverse(ll a)
    {
        ll temp = Pow(a, mod - 2) % mod;
        return temp;
    }
    ll modularNcr(ll n, ll r)
    {
        if (r < 0 || r > n)
            return 0;

        ll nmr = fact[n];
        ll dmr1 = fact[r];
        ll dmr2 = fact[n - r];
        ll ans = (1LL * nmr * modularInverse(dmr1) % mod *
                  modularInverse(dmr2) % mod) %
                 mod;
        return ans;
    }
    void findSets(vector<vector<int>> &dp, vector<ll> &count, int m)
    {
        if (dp[m][1] != 0)
            return;
        dp[m][1] = 1;
        count[1]++;
        for (int j = 2; j <= m; j++)
        {
            if (m % j == 0)
            {
                findSets(dp, count, m / j);
                for (int i = 1; i < 15; i++)
                {
                    if (dp[m / j][i])
                    {
                        dp[m][i + 1] = (dp[m][i + 1] + dp[m / j][i]) % mod;
                        count[i + 1] = (count[i + 1] + dp[m / j][i]) % mod;
                    }
                }
            }
        }
    }
    int idealArrays(int n, int maxValue)
    {
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            fact[i] = (i * fact[i - 1]) % mod;
        }
        vector<vector<int>> dp(maxValue + 1, vector<int>(15, 0));
        vector<ll> count(15, 0);
        for (int i = 1; i <= maxValue; i++)
        {
            findSets(dp, count, i);
        }
        int ans = 0;
        for (int i = 1; i < 15; i++)
        {
            if (count[i] > 0)
            {

                ans = (ans + (count[i] * modularNcr(n - 1, i - 1) % mod)) % mod;
            }
        }
        return ans;
    }
};
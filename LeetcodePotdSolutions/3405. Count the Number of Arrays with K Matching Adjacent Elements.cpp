class Solution
{
public:
#define ll long long
    long long mod = 1e9 + 7;
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
    ll moduloInverse(ll a)
    {
        ll ans = (Pow(a, mod - 2) % mod);
        return ans;
    }
    ll modularNcr(ll n, ll r)
    {
        if (r < 0 || n < 0 || r > n)
            return 0;
        if (r == 0)
            return 1;
        vector<ll> fact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = (fact[i - 1] * i) % mod;
        ll nmr = fact[n];
        ll dmr1 = fact[r];
        ll dmr2 = fact[n - r];
        return 1LL *
               (nmr * moduloInverse(dmr1) % mod * moduloInverse(dmr2) % mod) %
               mod;
    }

    int countGoodArrays(int n, int m, int k)
    {
        int r = n - k;
        ll res = modularNcr(n - 1, k);
        res = (res * m) % mod;
        ll temp = Pow(m - 1, r - 1);
        res = (res * temp) % mod;
        return res % mod;
    }
};
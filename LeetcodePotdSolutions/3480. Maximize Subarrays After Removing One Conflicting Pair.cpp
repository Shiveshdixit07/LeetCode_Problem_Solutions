class Solution
{
public:
#define ll long long
    long long maxSubarrays(int n, vector<vector<int>> &c)
    {
        vector<pair<ll, ll>> mp(n + 1);
        for (auto &e : c)
        {
            int a = e[0];
            int b = e[1];
            if (a > b)
                swap(a, b);
            auto &[p, q] = mp[b];
            if (p < a)
            {
                q = p;
                p = a;
            }
            else if (q < a)
            {
                q = a;
            }
        }
        vector<ll> gain(n + 1);

        ll mx = 0, smx = 0;
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            auto [mx1, mx2] = mp[i];
            if (mx1 > 0)
            {
                if (mx1 > mx)
                {
                    smx = max(mx, mx2);
                    mx = mx1;
                }
                else if (smx < mx1)
                {
                    smx = mx1;
                }
            }
            ans += (i - mx);
            gain[mx] += (mx - smx);
        }
        return 0LL + ans + *max_element(gain.begin(), gain.end());
    }
};
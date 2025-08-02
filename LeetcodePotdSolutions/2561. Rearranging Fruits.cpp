class Solution
{
public:
#define ll long long
    long long minCost(vector<int> &b1, vector<int> &b2)
    {
        unordered_map<ll, ll> mp, m1, m2;
        ll l = b1.size();
        ll mini = *min_element(b1.begin(), b1.end());
        ll mini1 = *min_element(b2.begin(), b2.end());
        ll fmini = min(mini, mini1);
        for (ll i = 0; i < l; i++)
        {
            mp[b1[i]]++;
            mp[b2[i]]++;
            m1[b1[i]]++;
            m2[b2[i]]++;
        }
        for (auto it : mp)
        {
            if (it.second % 2 == 1)
            {
                return -1;
            }
        }
        for (auto &it : mp)
        {
            it.second = it.second / 2;
        }
        vector<ll> extra;
        vector<ll> need;
        for (auto it : mp)
        {

            if (m1.find(it.first) == m1.end())
            {
                while (it.second--)
                {
                    need.push_back(it.first);
                }
            }
            else if (m1.find(it.first) != m1.end())
            {
                if (m1[it.first] == it.second)
                {
                    continue;
                }
                ll diff = m1[it.first] - it.second;
                if (diff < 0)
                {
                    ll dif = abs(diff);
                    while (dif--)
                    {
                        need.push_back(it.first);
                    }
                }
                else
                {
                    while (diff--)
                    {
                        extra.push_back(it.first);
                    }
                }
            }
        }
        sort(need.begin(), need.end());
        sort(extra.begin(), extra.end());
        ll ans = 0;
        for (int i = 0; i < need.size(); i++)
        {
            ans += min(min(need[i], extra[need.size() - i - 1]), 2 * fmini);
        }

        return ans;
    }
};
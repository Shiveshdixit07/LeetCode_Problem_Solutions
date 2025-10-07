class Solution
{
public:
    vector<int> avoidFlood(vector<int> &r)
    {
        set<int> st;
        unordered_map<int, int> mp;
        vector<int> ans(r.size());
        for (int i = 0; i < r.size(); i++)
        {
            if (r[i] > 0)
            {
                if (mp.count(r[i]))
                {
                    if (st.empty())
                        return {};
                    auto it = st.lower_bound(mp[r[i]]);
                    if (it == st.end())
                        return {};

                    mp[r[i]] = i;
                    ans[*it] = r[i];
                    st.erase(it);
                }
                else
                {
                    mp[r[i]] = i;
                }
                ans[i] = -1;
            }
            else
            {
                st.insert(i);
            }
        }
        for (int i = 0; i < r.size(); i++)
        {
            if (ans[i] == 0)
                ans[i] = 1;
        }
        return ans;
    }
};
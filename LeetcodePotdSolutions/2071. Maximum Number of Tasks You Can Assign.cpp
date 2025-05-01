class Solution
{
public:
    bool chk(int k, vector<int> &t, int p, int s, vector<int> &w)
    {
        multiset<int> st(w.begin(), w.begin() + k);
        for (int i = k - 1; i >= 0; i--)
        {
            auto last = prev(st.end());
            if (*last >= t[i])
            {
                st.erase(last);
            }
            else if (p > 0)
            {
                auto it = st.lower_bound(t[i] - s);
                if (it == st.end())
                    return 0;
                st.erase(it);
                p--;
            }
            else
            {
                return 0;
            }
        }
        return 1;
    }
    int maxTaskAssign(vector<int> &t, vector<int> &w, int p, int s)
    {
        int n = t.size();
        int m = w.size();

        sort(t.begin(), t.end());
        sort(w.begin(), w.end(), greater<>());
        int l = 0, h = min(n, m);
        while (l <= h)
        {
            int mid = l + ((h - l) >> 1);
            if (chk(mid, t, p, s, w))
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        return h;
    }
};
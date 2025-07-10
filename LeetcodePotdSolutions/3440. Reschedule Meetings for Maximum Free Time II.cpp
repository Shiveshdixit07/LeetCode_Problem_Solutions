class Solution
{
public:
    int maxFreeTime(int et, vector<int> &s, vector<int> &e)
    {
        vector<int> t;
        int prev = 0;
        int n = e.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            t.push_back(s[i] - prev);
            ans = max(ans, t.back());
            prev = e[i];
        }
        t.push_back(et - prev);
        ans = max(ans, t.back());
        vector<int> Prev(t.size()), after(t.size());

        int mx = 0;
        for (int i = 0; i < t.size(); i++)
        {
            Prev[i] = mx;
            mx = max(mx, t[i]);
        }
        mx = 0;
        for (int i = t.size() - 1; i >= 0; i--)
        {
            after[i] = mx;
            mx = max(mx, t[i]);
        }

        for (int i = 1; i < t.size(); i++)
        {
            int req = e[i - 1] - s[i - 1];
            if (Prev[i - 1] >= req || after[i] >= req)
            {
                ans = max(ans, t[i] + t[i - 1] + req);
            }
            else
            {
                ans = max(ans, t[i] + t[i - 1]);
            }
        }
        return ans;
    }
};
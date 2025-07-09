class Solution
{
public:
    int maxFreeTime(int et, int k, vector<int> &s, vector<int> &e)
    {
        int prev = 0;
        int n = s.size();
        vector<int> t;
        for (int i = 0; i < n; i++)
        {
            t.push_back(s[i] - prev);
            prev = e[i];
        }
        t.push_back(et - prev);
        int sum = 0;
        int ans = 0;
        int i = 0;
        for (i; i < t.size() && i <= k; i++)
        {
            sum += t[i];
        }
        ans = max(ans, sum);
        for (i; i < t.size(); i++)
        {
            sum -= t[i - k - 1];
            sum += t[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};
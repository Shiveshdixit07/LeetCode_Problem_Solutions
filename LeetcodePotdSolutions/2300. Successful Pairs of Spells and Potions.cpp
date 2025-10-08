class Solution
{
public:
    vector<int> successfulPairs(vector<int> &s, vector<int> &p, long long ss)
    {
        int n = s.size();
        vector<int> ans(n);
        sort(p.begin(), p.end());
        for (int i = 0; i < n; i++)
        {
            long long temp = ceil((1.0 * ss) / s[i]);
            int req = p.end() - lower_bound(p.begin(), p.end(), temp);
            ans[i] = req;
        }
        return ans;
    }
};
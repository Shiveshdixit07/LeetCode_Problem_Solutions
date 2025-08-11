class Solution
{
public:
    const int mod = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>> &q)
    {
        vector<int> vt;
        int idx = 0;
        while (n > 0)
        {
            if (n & 1)
            {
                vt.push_back((1 << idx));
            }
            idx++;
            n /= 2;
        }
        int len = q.size();
        vector<int> ans;
        for (int i = 0; i < len; i++)
        {
            long long val = 1;
            for (int j = q[i][0]; j <= q[i][1]; j++)
            {
                val = (1LL * val * vt[j]) % mod;
            }

            ans.push_back(val);
        }
        return ans;
    }
};

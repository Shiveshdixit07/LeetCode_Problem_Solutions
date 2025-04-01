class Solution
{
public:
#define ll long long
    ll dp[(int)1e5 + 1];
    ll solve(vector<vector<int>> &q, int idx)
    {
        if (idx >= q.size())
        {
            return 0LL;
        }
        if (dp[idx] != -1)
            return dp[idx];

        ll temp = solve(q, idx + 1);
        ll temp2 = solve(q, idx + q[idx][1] + 1) + 0LL + q[idx][0];
        return dp[idx] = max(temp, temp2);
    }
    long long mostPoints(vector<vector<int>> &q)
    {
        memset(dp, -1, sizeof(dp));
        return solve(q, 0);
    }
};